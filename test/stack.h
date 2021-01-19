#pragma once
#include <stdio.h>

typedef enum Errors_t
{
    None,
    PopOutOfRange,
    AllocationNotSecseed,
}Errors;


#define StackValueType int
/**
 * @brief Data structure for an item in the stack
*/
typedef struct StackItem_t
{
    StackValueType value;
    struct StackItem_t *next;

}StackItem;

/**
 * @brief Data structure for the stack
*/
typedef struct Stack_t
{
    int lastError;
    size_t stackSize;
    StackItem *root;

}Stack;

/**
 * @brief Stack constractor the is need to free the memory in the end
 * @return pointer to the new Stack
*/
Stack *CreateStack();

/**
 * @brief Delete the Stack
 * @param stack Pointer to delete Stack
*/
void DeleteStack(Stack * stack);

/**
 * @brief Push an item to the top of the stack
 * @param stack     The stack we want to add an item to
 * @param item      the item we want to add to the stack
*/
void StackPush(Stack *stack, StackValueType item);

/**
 * @brief pop an item from the top of the stack and return the item
 * @param stack The stack we want to pop from
 * @return The item that was at the top of the stack 
*/
StackValueType StackPop(Stack *stack);

/**
 * @brief return the last Error
 * @param stack the stack the erorr hpend
 * @return error code 
*/
int StackGetLastError(Stack *stack);

/**
 * @brief Print the Stack
 * @param stack the stack to print
*/
void StackPrint(Stack *stack);

/**
 * @brief return the size of the stack
 * @param stack the stack
 * @return the size of the given stack
*/
size_t StackSize(Stack *stack);


