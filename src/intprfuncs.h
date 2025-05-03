#pragma once
#ifndef INTPRFUNCS_H
#define INTPRFUNCS_H

#include <stdio.h>

#define SUCCESS 0
#define FAIL -1

#define DATA_SIZE 0x8000

int getfilename(int argc, char* argv[], char* filename);

int openfile(FILE** fptr, char* filename);

// main interpreter function
int interpret(FILE* fptr, char* data);

#endif