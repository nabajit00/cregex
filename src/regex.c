#include "char.h"
#include "regex.h"
#include <stdlib.h>
#include<string.h>

char message[100];

CharStruct* validateString(char* str){
    CharStruct *charStruct = malloc(sizeof(CharStruct));
    int len = strlen(str);
    charStruct->chars = malloc(sizeof(char)*len);

    int i=0;
    for(;i<len;i++){
        if(str[i]=='/'){
            if(i<len - 1){

            }else{
                strcpy(message,"Dangling escaping");
                return NULL;
            }
        }
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
