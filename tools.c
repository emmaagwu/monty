#include "monty.h"

/**
 * openFile - Function to open a file.
 * @fileName: The path of the file to be opened.
 */
void openFile(char *fileName)
{
	FILE *fileDescriptor = fopen(fileName, "r");

	if (fileName == NULL || fileDescriptor == NULL)
		handleErrors(2, fileName);

	readFile(fileDescriptor);
	fclose(fileDescriptor);
}

/**
 * readFile - Function to read the contents of a file.
 * @fileDescriptor: Pointer to the file descriptor.
 */
void readFile(FILE *fileDescriptor)
{
	int lineNumber, format = 0;
	char *buffer = NULL;
	size_t length = 0;
	ssize_t line = getline(&buffer, &length, fileDescriptor);

	for (lineNumber = 1; line != -1; lineNumber++)
	{
		format = parseLine(buffer, lineNumber, format);
	}
	free(buffer);
}

/**
 * parseLine - Function to tokenize each line.
 * @buffer: Line content from the file.
 * @lineNumber: Current line number being processed.
 * @format: Storage format (0 for stack, 1 for queue).
 * Return: 0 if the operation is stack, 1 if queue.
 */
int parseLine(char *buffer, int lineNumber, int format)
{
	char *opcode, *value;
	const char *delimiter = "\n ";

	if (buffer == NULL)
		handleErrors(4);

	opcode = strtok(buffer, delimiter);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delimiter);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	findFunction(opcode, value, lineNumber, format);
	return (format);
}

/**
 * findFunction - Function to locate and execute the operation by opcode.
 * @opcode: Opcode to be processed.
 * @value: Argument associated with the opcode.
 * @lineNumber: Current line number being processed.
 * @format: Storage format (0 for stack, 1 for queue).
 */
void findFunction(char *opcode, char *value, int lineNumber, int format)
{
	int i;
	int flag;

	instruction_t functionList[] = {
		{"push", pushToStack},
		{"pall", printStack},
		{"pint", printTopStack},
		{"pop", popFromStack},
		{"nop", noOperation},
		{"swap", swapStackNodes},
		{"add", addNodes},
		{"sub", subNodes},
		{"div", divNodes},
		{"mul", mulNodes},
		{"mod", modNodes},
		{"pchar", printCharacter},
		{"pstr", printString},
		{"rotl", rotateLeft},
		{"rotr", rotateRight},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; functionList[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, functionList[i].opcode) == 0)
		{
			callFunction(functionList[i].f, opcode, value, lineNumber, format);
			flag = 0;
		}
	}
	if (flag == 1)
		handleErrors(3, lineNumber, opcode);
}

/**
 * callFunction - Function to invoke the required operation.
 * @func: Pointer to the function to be called.
 * @op: String representing the opcode.
 * @val: String representing a numeric value.
 * @ln: Line number of the instruction.
 * @format: Format specifier (0 for stack, 1 for queue).
 */
void callFunction(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			handleErrors(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				handleErrors(5, ln);
		}
		node = createNode(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			addToQueue(&node, ln);
	}
	else
		func(&stackTop, ln);
}

