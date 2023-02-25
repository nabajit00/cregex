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

void addChar(CharStruct *cs,char ch,char isSpecial,int pos);

void freeCharStruct(CharStruct *charStruct);
CharStruct* newCharStruct(int len);
get(CharStruct* charStruct,int pos);

#endif
