#include "monty.h"

/**
 * printCharacter - Prints the ASCII value.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void printCharacter(stack_t **stack, unsigned int line_number)
{
	int ascii;
    if (!stack || !(*stack))
    {
        handleStringErrors(11, line_number);
        return;
    }

    ascii = (*stack)->n;
    if (ascii < 0 || ascii > 127)
    {
        handleStringErrors(10, line_number);
        return;
    }

    printf("%c\n", ascii);
}

/**
 * printString - Prints a string.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void printString(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp;
	int ascii;

    if (!stack || !(*stack))
    {
        printf("\n");
        return;
    }

    temp = *stack;
    while (temp != NULL)
    {
        ascii = temp->n;
        if (ascii <= 0 || ascii > 127)
            break;
        printf("%c", ascii);
        temp = temp->next;
    }
    printf("\n");
}

/**
 * rotateLeft - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void rotateLeft(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp;
    if (!stack || !(*stack) || !((*stack)->next))
        return;

    temp = *stack;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = *stack;
    (*stack)->prev = temp;
    *stack = (*stack)->next;
    (*stack)->prev->next = NULL;
    (*stack)->prev = NULL;
}

/**
 * rotateRight - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void rotateRight(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp;
    if (!stack || !(*stack) || !((*stack)->next))
        return;

    temp = *stack;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = *stack;
    temp->prev->next = NULL;
    temp->prev = NULL;
    (*stack)->prev = temp;
    (*stack) = temp;
}

