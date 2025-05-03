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
    if (*fptr == NULL) {
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
        index++;
        int bracketCount = 0;
        switch (ch) {
            // increment data pointer
            case '>':
                dataIndex++;
                if (dataIndex >= DATA_SIZE) {
                    printf("Out of data range, attempted access at %d.\n", dataIndex);
                    return FAIL;
                }
                break;
            // decrement data pointer
            case '<':
                dataIndex--;
                if (dataIndex < 0) {
                    printf("Out of data range, attempted access at %d.\n", dataIndex);
                    return FAIL;
                }
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
                data[dataIndex] = getchar();
                break;
            // if data == 0, jump forward to matching ]
            case '[':
                if (data[dataIndex] != 0) {
                    break;
                }
                while ((ch = fgetc(fptr))) {
                    index++;
                    if (ch == ']') {
                        if (bracketCount == 0) {
                            break;
                        }
                        bracketCount--;
                    }
                    else if (ch == '[') {
                        bracketCount++;
                    }
                }
                break;
            // if data != 0, jump backward to matching [
            case ']':
                if (data[dataIndex] == 0) {
                    break;
                }
                fseek(fptr, -2, SEEK_CUR);
                index -= 2;
                while ((ch = fgetc(fptr))) {
                    index++;
                    if (ch == '[') {
                        if (bracketCount == 0) {
                            break;
                        }
                        bracketCount--;
                    }
                    else if (ch == ']') {
                        bracketCount++;
                    }
                    fseek(fptr, -2, SEEK_CUR);
                    index -= 2;
                    if (index < 0) {
                        printf("Out of instruction range, attempted access at %d.\n", index);
                        return FAIL;
                    }
                }
                break;
            default:
                break;
        }
    }

    return SUCCESS;
}
