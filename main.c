
#include "monty.h"

stack_t *stackTop = NULL;

/**
 * main - Entry point for the Monty interpreter.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 *
 * Return: Always 0 if successful.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	openFile(argv[1]);
	freeNodes();
	return (0);
}

/**
 * createNode - Creates a new node with the given value.
 * @value: Value to be stored in the new node.
 *
 * Return: Pointer to the newly created node.
 */
stack_t *createNode(int value)
{
	stack_t *newNode = malloc(sizeof(stack_t));

	if (newNode == NULL)
		handleErrors(4);

	newNode->n = value;
	newNode->prev = NULL;
	newNode->next = NULL;
	return (newNode);
}

/**
 * freeNodes - Frees all nodes in the stack.
 */
void freeNodes(void)
{
	stack_t *tmp;

	if (stackTop == NULL)
		return;

	while (stackTop != NULL)
	{
		tmp = stackTop;
		stackTop = stackTop->next;
		free(tmp);
	}
}

/**
 * addToQueue - Adds a new node to the queue.
 * @newNode: Pointer to the new node to be added.
 * @lineNumber: Line number of the opcode.
 */
void addToQueue(stack_t **newNode, __attribute__((unused))unsigned int lineNumber)
{
	stack_t *tmp;

	if (newNode == NULL || *newNode == NULL)
		exit(EXIT_FAILURE);

	if (stackTop == NULL)
	{
		stackTop = *newNode;
		return;
	}

	tmp = stackTop;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *newNode;
	(*newNode)->prev = tmp;
}

