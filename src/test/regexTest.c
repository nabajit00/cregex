#include<assert.h>
#include "../char.h"
#include "../regex.h"
#include<stdlib.h>
#include<stdio.h>
void validateStringTest(){
    //TODO: complete the testcases
    CharStruct *cs = validateString("");
    assert(cs==NULL);
    freeCharStruct(cs);
    cs = validateString("ab*(a|b)");
    assert(cs != NULL);
    cs = validateString("ab*(a|b)");
    assert(cs != NULL);
    cs = validateString("ab*((a|b)");
    assert(cs == NULL);
    printf("%s",getLastError());
}