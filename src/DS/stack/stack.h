#ifndef STACK_H
#define STACK_H

struct stack {
    int size;
    int pos; //insert position
    char* symbols;
 };
typedef struct stack Stack;

Stack* createStack(int size);
void freeStack(Stack*);

void stackPush(Stack* stack,char ch);

char stackPop(Stack* stack);
char isStackEmpty(Stack* stack);

#endif