/***
 * Using Shunting yard algorithm convert to postfix expresssion
*/
#include<stdlib.h>
#include<string.h>
#include "./DS/stack/stack.h"

char* toPostfix(const char* str){
    int len = strlen(str);
    int i=0;
    Stack* stack = createStack(len);
    for(;i<len;i++){
        if(str[i] == '*' || str[i] == '|'){
            
        }
    }
    freeStack(stack);
}