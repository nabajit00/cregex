#include<assert.h>
#include "../char.h"
#include "../regex.h"
void validateStringTest(){
    CharStruct cs = validateString("");
    assert(cs==NULL);
}

void validateRegEx(){
    validateStringTest();
}