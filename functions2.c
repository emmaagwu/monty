#include "monty.h"

/**
 * noOperation - Performs no operation.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void noOperation(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}

/**
 * swapStackNodes - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void swapStackNodes(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *next;
    if (!stack || !(*stack) || !((*stack)->next))
    {
        handleMoreErrors(8, line_number, "swap");
        return;
    }

    top = *stack;
    next = top->next;

    top->next = next->next;
    if (next->next)
        next->next->prev = top;

    next->next = top;
    top->prev = next;
    next->prev = NULL;

    *stack = next;
}

/**
 * add_top_two - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void addNodes(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
    if (!stack || !(*stack) || !((*stack)->next))
    {
        handleMoreErrors(8, line_number, "add");
        return;
    }

    top = *stack;
    *stack = top->next;

    (*stack)->n += top->n;
    free(top);
    (*stack)->prev = NULL;
}

/**
 * subtract_top_two - Subtracts the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void subNodes(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
    if (!stack || !(*stack) || !((*stack)->next))
    {
        handleMoreErrors(8, line_number, "sub");
        return;
    }

    top = *stack;
    *stack = top->next;

    (*stack)->n -= top->n;
    free(top);
    (*stack)->prev = NULL;
}

/**
 * divide_top_two - Divides the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void divNodes(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
    if (!stack || !(*stack) || !((*stack)->next))
    {
        handleMoreErrors(8, line_number, "div");
        return;
    }

    if ((*stack)->n == 0)
    {
        handleMoreErrors(9, line_number);
        return;
    }

    top = *stack;
    *stack = top->next;

    (*stack)->n /= top->n;
    free(top);
    (*stack)->prev = NULL;
}

