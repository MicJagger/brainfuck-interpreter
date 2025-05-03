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
