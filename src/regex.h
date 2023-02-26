#ifndef REGEX_H
#define REGEX_H

struct Parser{
    
};
typedef struct Parser Parser;

CharStruct* validateString(char* str);

Parser* constructParser(char* str);

const char* getLastError();

#endif