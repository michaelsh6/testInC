#include <stdio.h>
#include "stack.h"



int main(void)
{
    Stack *stack = CreateStack();
    StackPop(stack);
    printf("the lst Error: %d\n", StackGetLastError(stack));
    StackPush(stack,5);
    StackPush(stack,4);
    StackPush(stack,3);
    StackPush(stack,2);
    StackPush(stack,1);
    StackPrint(stack);
    int topStack =  StackPop(stack);
    printf("the top value in the stack was %d\n", topStack);
    StackPrint(stack);
    DeleteStack(stack);
    return 0;
}