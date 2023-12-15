#include "monty.h"

/**
 * pushToStack - Adds a node to the stack.
 * @newNode: Pointer to the new node.
 * @ln: Integer representing the line number of the opcode.
 */
void pushToStack(stack_t **newNode, __attribute__((unused)) unsigned int ln)
{
	stack_t *tmp;

	if (!newNode || !(*newNode))
		exit(EXIT_FAILURE);

	if (stackTop == NULL)
	{
		stackTop = *newNode;
		return;
	}

	tmp = stackTop;
	stackTop = *newNode;
	stackTop->next = tmp;
	tmp->prev = stackTop;
}

/**
 * printStack - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void printStack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;

	if (!stack)
		exit(EXIT_FAILURE);

	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * popFromStack - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void popFromStack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!stack || !(*stack))
		handleMoreErrors(7, line_number);

	tmp = *stack;
	*stack = tmp->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(tmp);
}

/**
 * printTopStack - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void printTopStack(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
		handleMoreErrors(6, line_number);

	printf("%d\n", (*stack)->n);
}

