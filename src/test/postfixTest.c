#include<string.h>
#include "../postfix.h"
#include "../regex.h"
#include<assert.h>
#include<stddef.h>
#include<stdio.h>

void validatePostFix(){
    char str[] = "a*(b|bc)";
    // printf("%s\n",str);
    CharStruct *cs = validateString(str);
    //printf("%s\n",getLastError());
    assert(cs != NULL);
    assert(cs->len == 8);
    int i=0;
    Char charT; 
    CharStruct *pcs = toPostfix(cs);
    assert(pcs!=NULL);
    printf("%d-->\n",pcs->len);
    // //assert(pcs->len == 6);
    for(i=0;i<pcs->len;i++){
        charT = getChar(pcs,i);
        printf("%c - %d\n",charT.ch,charT.isSpecial);   
    }
}