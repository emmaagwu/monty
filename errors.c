#include "monty.h"

/**
 * handleErrors - Displays appropriate error messages based on the error code.
 * @errorCode: The error codes and their meanings:
 * (1) => User provides no file or more than one file to the program.
 * (2) => The provided file cannot be opened or read.
 * (3) => The file contains an unknown instruction.
 * (4) => Malloc fails to allocate memory.
 * (5) => Parameter passed to "push" instruction is not an int.
 * (6) => Stack is empty for "pint" operation.
 * (7) => Stack is empty for "pop" operation.
 * (8) => Stack is too short for operation.
 * (9) => Division by zero.
 */
void handleErrors(int errorCode, ...)
{
	va_list arguments;
	char *op;
	int lineNumber;

	va_start(arguments, errorCode);

	if (errorCode == 1)
	{
		fprintf(stderr, "USAGE: monty file\n");
	}
	else if (errorCode == 2)
	{
		fprintf(stderr, "Error: Can't open file %s\n", va_arg(arguments, char *));
	}
	else if (errorCode == 3)
	{
		lineNumber = va_arg(arguments, int);
		op = va_arg(arguments, char *);
		fprintf(stderr, "L%d: unknown instruction %s\n", lineNumber, op);
	}
	else if (errorCode == 4)
	{
		fprintf(stderr, "Error: malloc failed\n");
	}
	else if (errorCode == 5)
	{
		fprintf(stderr, "L%d: usage: push integer\n", va_arg(arguments, int));
	}

	freeNodes();
	exit(EXIT_FAILURE);
}

/**
 * handleMoreErrors - Handles additional errors.
 * @errorCode: The error codes and their meanings:
 * (6) => Stack is empty for "pint" operation.
 * (7) => Stack is empty for "pop" operation.
 * (8) => Stack is too short for operation.
 * (9) => Division by zero.
 */
void handleMoreErrors(int errorCode, ...)
{
	va_list arguments;
	char *op;
	int lineNumber;

	va_start(arguments, errorCode);

	if (errorCode == 6)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(arguments, int));
	}
	else if (errorCode == 7)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(arguments, int));
	}
	else if (errorCode == 8)
	{
		lineNumber = va_arg(arguments, unsigned int);
		op = va_arg(arguments, char *);
	fprintf(stderr, "L%d: can't %s, stack too short\n", lineNumber, op);	}
	else if (errorCode == 9)
	{
		fprintf(stderr, "L%d: division by zero\n", va_arg(arguments, unsigned int));
	}

	freeNodes();
	exit(EXIT_FAILURE);
}

/**
 * handleStringErrors - Handles string-related errors.
 * @errorCode: The error codes and their meanings:
 * (10) ~> The number inside a node is outside ASCII bounds.
 * (11) ~> The stack is empty.
 */
void handleStringErrors(int errorCode, ...)
{
	va_list arguments;
	int lineNumber;

	va_start(arguments, errorCode);
	lineNumber = va_arg(arguments, int);

	if (errorCode == 10)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", lineNumber);
	}
	else if (errorCode == 11)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", lineNumber);
	}

	freeNodes();
	exit(EXIT_FAILURE);
}

