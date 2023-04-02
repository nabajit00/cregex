#ifndef REGEX_H
#define REGEX_H
#include "./parser.h"

CharStruct* validateString(char* str);

Parser* constructParser(char* str);

const char* getLastError();

#endif