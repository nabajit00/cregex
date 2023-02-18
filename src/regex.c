#include "char.h"
#include "regex.h"
#include <stdlib.h>
#include<string.h>

char message[100];

/**
 * @brief validate regex string, by recognising escaped charcter, validating brackets
 * 
 * @param str 
 * @return CharStruct* 
 */
CharStruct* validateString(char* str){
    int len = strlen(str);
    if(len==0){
        return NULL;
        strncpy(message,"Empty String",100);
    }
    CharStruct *charStruct = malloc(sizeof(CharStruct));
    charStruct->chars = malloc(sizeof(char)*len);

    int i=0;
    int danglingBrackets = 0;
    for(;i<len;i++){
        if(str[i]=='/'){
            //Escaped char next char no matter what will be no special
            if(i<len - 1){
                charStruct->chars[i] = newChar(str[i++],0);
            }else{
                snprintf(message,100,"Dangling escape char '//' in position %d",i);
                free(charStruct);
                return NULL;
            }
        } else{
            if(str[i] == '('){
                danglingBrackets++;
                charStruct->chars[i] = newChar(str[i],1);
            } else if(str[i] == ')'){
                if(danglingBrackets == 0){
                    snprintf(message,100,"Mismatched ')' in position %d",i);
                    free(charStruct);
                    return NULL;
                }
                danglingBrackets--;
                charStruct->chars[i] = newChar(str[i],1);
            } else if(str[i]=='*' || str[i]=='|'){
                charStruct->chars[i] = newChar(str[i],1);
            } else{
                charStruct->chars[i] = newChar(str[i],0);
            }
        }
    }
    if(danglingBrackets){
        strncpy(message,"Mismatched brackets",100);
        free(charStruct);
        return NULL;
    }
    return charStruct;
}

Parser* constructRegex(char* str){
    message[0]=0;
    CharStruct* charStruct = validateString(str);
    if(charStruct == NULL){
        return NULL;
    }
}

const char* getError(){
    return message;
}

Char newChar(char ch,char isSpecial){
    Char charT;
    charT.ch = ch;
    charT.isSpecial = isSpecial;
    return charT;
}
