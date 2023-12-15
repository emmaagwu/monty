#include "monty.h"

/**
 * mulNodes - Multiplies the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void mulNodes(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (!stack || !(*stack) || !((*stack)->next))
	{
		handleMoreErrors(8, line_number, "mul");
		return;
	}

	top = *stack;
	*stack = top->next;

	(*stack)->n *= top->n;
	free(top);
	(*stack)->prev = NULL;
}

/**
 * modNodes - Computes the modulo of the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void modNodes(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (!stack || !(*stack) || !((*stack)->next))
	{
		handleMoreErrors(8, line_number, "mod");
		return;
	}

	if ((*stack)->n == 0)
	{
		handleMoreErrors(9, line_number);
		return;
	}

	top = *stack;
	*stack = top->next;

	(*stack)->n %= top->n;
	free(top);
	(*stack)->prev = NULL;
}

