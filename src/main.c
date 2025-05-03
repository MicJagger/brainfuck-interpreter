#include <stdio.h>

#include "intprfuncs.h"

int main(int argc, char* argv[]) {
    char filename[FILENAME_MAX];
    for (int i = 0; i < FILENAME_MAX; i++) {
        filename[i] = '\0';
    }
    FILE* fptr;

    getfilename(argc, argv, filename);
    if (openfile(&fptr, filename) < SUCCESS) {
        printf("Failed to open file.\n");
        return FAIL;
    }

    char ch;
    while ((ch = fgetc(fptr)) != EOF) {
        printf("%c", ch);
    }
    
    fclose(fptr);

    return SUCCESS;
}
