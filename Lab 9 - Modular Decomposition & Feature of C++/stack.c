#ifndef STACK_H
#define STACK_H

typedef struct stack {
    char letter;
    struct stack *next;
} Stack;

typedef Stack *stackPtr;

stackPtr push(stackPtr topPtr, char c);
stackPtr pop(stackPtr topPtr, char *c);

#endif
