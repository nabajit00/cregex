#include "char.h";

void addChar(CharStruct *cs,char ch,char isSpecial, int pos){
    Char charT;
    charT.ch = ch;
    charT.isSpecial = isSpecial;
    cs->chars[pos] = charT;
}

void freeCharStruct(CharStruct *charStruct){
    if(charStruct != NULL){
        free(charStruct->chars);
        free(charStruct);
    }
}

CharStruct* newCharStruct(int len){
    CharStruct *charStruct = malloc(sizeof(CharStruct));
    charStruct->len=0;
    charStruct->chars = malloc(sizeof(char)*len);
    return charStruct;
}

CharT get(CharStruct* cs,int pos){
    return cs->chars[pos];
}