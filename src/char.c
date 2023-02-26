/**
 * @file char.c
 * @author Nabajit Upadhyaya
 * @brief CharStruct with special char * | () info 
 * 
 */
#include<stdlib.h>
#include "char.h"

void addChar(CharStruct *cs,char ch,char isSpecial){
    Char charT;
    charT.ch = ch;
    charT.isSpecial = isSpecial;
    cs->chars[cs->len++] = charT;
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

Char getChar(CharStruct* cs,int pos){
    return cs->chars[pos];
}