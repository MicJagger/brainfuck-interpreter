#include <stdio.h>

int main(int argc, char* argv[]) {
    char filename[32];
    if (argc == 1) {
        printf("Input file name: ");
        scanf("%31s", &filename);
    }
    else {
        snprintf(filename, 31, argv[1]);
    }
    printf("Running: %s", filename);


    return 0;
}