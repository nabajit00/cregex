#ifndef STACK_H
#define STACK_H

struct stack {
    int size;
    int pos; //insert position
    int* symbols;
 };
typedef struct stack Stack;

Stack* createStack(int size);
void freeStack(Stack*);

void stackPush(Stack* stack,int i);

int stackPop(Stack* stack);
char isStackEmpty(Stack* stack);
int peekStack(Stack*);

#endif