#include "stack.h"



Stack *CreateStack()
{

    Stack *stack = (Stack *)malloc(sizeof(stack));
    stack->stackSize = 0;
    stack->lastError = None;

    return stack;
}

void DeleteStack(Stack *stack)
{
    StackItem *currentItem = stack->root;
    StackItem *nextItem;

    for (size_t i = 1; i < stack->stackSize; i++)
    {
        nextItem = currentItem->next;
        free(currentItem);
        currentItem = nextItem;
    }
}




void StackPush(Stack *stack, StackValueType item)
{
    StackItem *newItem = (StackItem *)malloc(sizeof(StackItem));
    if (newItem == NULL)
    {
        stack->lastError = AllocationNotSecseed;
        return;
    }
     
    newItem->next = stack->root;
    newItem->value = item;
    stack->root = newItem;
    stack->stackSize += 1;
}

StackValueType StackPop(Stack *stack)
{
    StackItem *firstItem = stack->root;
    if (stack->stackSize == 0)
    {
        stack->lastError = PopOutOfRange;
        return -1;
    }
    StackValueType value = firstItem->value;
    StackItem *newRoot = firstItem->next;
    
    free(firstItem);
    stack->root = newRoot;
    stack->stackSize -= 1;
    return value;
}

int StackGetLastError(Stack *stack)
{
    return stack->lastError;
}

size_t StackSize(Stack *stack)
{
    return stack->stackSize;
}

void StackPrint(Stack *stack)
{
    printf("the stack values is\n");
    StackItem *currentItem = stack->root;
    for (size_t i = 0; i < stack->stackSize; i++)
    {
        printf("%d\n", currentItem->value);
        currentItem = currentItem->next;
    }
}
