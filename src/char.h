#ifndef CHARSTRUCT_H
#define CHARSTRUCT_H

struct Char{
    char ch;
    char isSpecial;
};
typedef struct Char Char;

struct CharStruct{
    int len;
    Char* chars;
};
typedef struct CharStruct CharStruct;

#endif
