#include <stdio.h>
#include <string.h>

#include "intprfuncs.h"

int main(int argc, char* argv[]) {
    int returnVal = SUCCESS;
    char filename[FILENAME_MAX];
    memset(filename, 0, FILENAME_MAX);
    FILE* fptr;

    getfilename(argc, argv, filename);
    if (openfile(&fptr, filename) < SUCCESS) {
        printf("Failed to open file.\n");
        return FAIL;
    }

    // initialize

    char data[DATA_SIZE];
    memset(data, 0, DATA_SIZE);

    // begin interpreter

    if (interpret(fptr, data) < SUCCESS) {
        returnVal = FAIL;
    }

    // cleanup
    
    fclose(fptr);

    return returnVal;
}
