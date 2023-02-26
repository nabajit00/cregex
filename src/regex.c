#include "char.h"
#include "regex.h"
#include <stdlib.h>
#include<string.h>
#include<stdio.h>
#include "util.h"

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

    CharStruct* charStruct = newCharStruct(len);

    int i=0;
    int danglingBrackets = 0;

    if(isOperator(str[0])){
        snprintf(message,100,"Can't start with %c",str[0]);
        freeCharStruct(charStruct);
        return NULL;
    }

    for(;i<len;i++){
        if(str[i]=='/'){
            //Escaped char next char no matter what will be no special
            if(i<len - 1){
                addChar(charStruct,str[i+1],0);
                i++;
            }else{
                snprintf(message,100,"Dangling escape char '\\' in position %d",i);
                freeCharStruct(charStruct);
                return NULL;
            }
        } else{
            if(str[i] == '('){
                danglingBrackets++;
                addChar(charStruct,str[i],1);
            } else if(str[i] == ')'){
                if(danglingBrackets == 0){
                    snprintf(message,100,"Mismatched ')' in position %d",i);
                    freeCharStruct(charStruct);
                    return NULL;
                }
                danglingBrackets--;
                addChar(charStruct,str[i],1);
            } else if(str[i]=='*' || str[i]=='|'){
                addChar(charStruct,str[i],1);
            } else{
                addChar(charStruct,str[i],0);
            }
        }
    }
    if(danglingBrackets){
        strncpy(message,"Mismatched brackets",100);
        freeCharStruct(charStruct);
        return NULL;
    }

    return charStruct;
}

/**
 * @brief Construct a parser from the regex expression which can be used to match
 * 
 * @param str 
 * @return Parser* 
 */
Parser* constructParser(char* str){
    message[0]=0;
    CharStruct* charStruct = validateString(str);
    if(charStruct == NULL){
        return NULL;
    } else{

    }
}

const char* getLastError(){
    return message;
}