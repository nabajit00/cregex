#include<stdlib.h>
#include "stack.h"

Stack* createStack(int size){
    Stack* stack = malloc(sizeof(Stack));
    stack->pos=0;
    stack->size = size;
    stack->symbols = malloc(sizeof(char)*size);
    return stack;
}

void freeStack(Stack* stack){
    free(stack->symbols);
    free(stack);
}

void stackPush(Stack* stack,char ch){
    if(stack->pos >= stack->size){
        realloc(stack->symbols,stack->size+5);
        stack->size += 5;
    }
    stack->symbols[stack->pos] = ch;
    stack->pos++;
}

char stackPop(Stack* stack){
    char output=-1;
    if(!isStackEmpty(stack)){
        output = stack->symbols[stack->pos-1];
        stack->pos--;
    }
    return output;
}

char isStackEmpty(Stack* stack){
    return stack->pos==0;
}