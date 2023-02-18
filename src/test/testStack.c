#include "../DS/stack/stack.h"
#include<assert.h>
#include<stdio.h>
int testStack(){
    Stack* stack = createStack(3);
    assert(stack);
    assert(stack->symbols);
    assert(stack->size == 3);
    assert(stack->pos == 0);
    assert(isStackEmpty(stack));

    stackPush(stack,'a');stackPush(stack,'b');
    assert(stack->pos == 2);

    stackPush(stack,'c');stackPush(stack,'d');
    assert(stack->pos == 4);assert(stack->size == 8);
    char c = stackPop(stack);
    assert(stack->pos == 3);
    assert(c == 'd');
    c = stackPop(stack);
    assert(stack->pos == 2);
    assert(c == 'c');
    freeStack(stack);
}