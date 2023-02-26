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

void stackPush(Stack* stack,int i){
    if(stack->pos >= stack->size){
        realloc(stack->symbols,stack->size+5);
        stack->size += 5;
    }
    stack->symbols[stack->pos] = i;
    stack->pos++;
}

int stackPop(Stack* stack){
    int output=-1;
    if(!isStackEmpty(stack)){
        output = stack->symbols[stack->pos-1];
        stack->pos--;
    }
    return output;
}

int peekStack(Stack* stack){
    int output=-1;
    if(!isStackEmpty(stack)){
        output = stack->symbols[stack->pos-1];
    }
    return output;
}

char isStackEmpty(Stack* stack){
    return stack->pos==0;
}