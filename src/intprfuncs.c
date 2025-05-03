#include "intprfuncs.h"

#include <stdio.h>

int getfilename(int argc, char* argv[], char* filename) {
    if (argc == 1) {
        printf("Input file name: ");
        fgets(filename, FILENAME_MAX, stdin);
        for (int i = 0; i < FILENAME_MAX; i++) {
            if (filename[i] == '\r' || filename[i] == '\n') {
                filename[i] = '\0';
            }
        }
    }
    else {
        snprintf(filename, FILENAME_MAX, argv[1]);
    }
    printf("Running: %s\n", filename);
    return SUCCESS;
}

int openfile(FILE** fptr, char* filename) {
    *fptr = fopen(filename, "r");
    if (fptr == NULL) {
        return FAIL;
    }
    return SUCCESS;
}


// interpreter

int interpret(FILE* fptr, char* data) {
    char ch;
    int index = 0;
    int dataIndex = 0;

    while ((ch = fgetc(fptr)) != EOF) {
        switch (ch) {
            // increment data pointer
            case '>':
                dataIndex++;
                break;
            // decrement data pointer
            case '<':
                dataIndex--;
                break;
            // increment byte at data pointer
            case '+':
                data[dataIndex]++;
                break;
            // decrement byte at data pointer
            case '-':
                data[dataIndex]--;
                break;
            // output byte at data pointer
            case '.':
                printf("%c", data[dataIndex]);
                break;
            // input byte to data pointer
            case ',':

                break;
            // if data == 0, jump forward to matching ]
            case '[':

                break;
            // if data != 0, jump backward to matching [
            case ']':

                break;
            default:
                break;
        }
        index++;
        if (index < 0) {
            printf("Out of instruction range, attempted access at %d.\n", index);
            return FAIL;
        }
        if (dataIndex < 0 || dataIndex >= DATA_SIZE) {
            printf("Out of data range, attempted access at %d.\n", dataIndex);
            return FAIL;
        }
    }

    //fseek(fptr, -2, SEEK_CUR);

    return SUCCESS;
}
