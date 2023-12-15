#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - Doubly linked list representation of a stack (or queue)
 * @n: Integer value of the node
 * @prev: Points to the previous element of the stack (or queue)
 * @next: Points to the next element of the stack (or queue)
 *
 * Description: Doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - Opcode and its function
 * @opcode: The opcode
 * @f: Function to handle the opcode
 *
 * Description: Opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *stackTop;
typedef void (*op_func)(stack_t **, unsigned int);

/* File operations */
void openFile(char *file_name);
int parseLine(char *buffer, int line_number, int format);
void readFile(FILE *);
void findFunction(char *, char *, int, int);

/* Stack operations */
stack_t *createNode(int n);
void freeNodes(void);
void printStack(stack_t **, unsigned int);
void pushToStack(stack_t **, unsigned int);
void addToQueue(stack_t **, unsigned int);

void callFunction(op_func, char *, char *, int, int);

void printTopStack(stack_t **, unsigned int);
void popFromStack(stack_t **, unsigned int);
void noOperation(stack_t **, unsigned int);
void swapStackNodes(stack_t **, unsigned int);

/* Math operations with nodes */
void addNodes(stack_t **, unsigned int);
void subNodes(stack_t **, unsigned int);
void divNodes(stack_t **, unsigned int);
void mulNodes(stack_t **, unsigned int);
void modNodes(stack_t **, unsigned int);

/* String operations */
void printCharacter(stack_t **, unsigned int);
void printString(stack_t **, unsigned int);
void rotateLeft(stack_t **, unsigned int);

/* Error handling */
void handleErrors(int error_code, ...);
void handleMoreErrors(int error_code, ...);
void handleStringErrors(int error_code, ...);
void rotateRight(stack_t **, unsigned int);

#endif


