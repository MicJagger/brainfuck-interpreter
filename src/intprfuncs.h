#pragma once
#ifndef INTPRFUNCS_H
#define INTPRFUNCS_H

#include <stdio.h>

#define SUCCESS 0
#define FAIL -1

int getfilename(int argc, char* argv[], char* filename);

int openfile(FILE** fptr, char* filename);

#endif