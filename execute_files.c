#include "monty.h"

/**
 * open_file - opens a file
 * @filename: the file name
 */

void open_file(char *filename)
{
	FILE *file = fopen(filename, "r");

	if (filename == NULL || file == NULL)
		error1(2, filename);

	read_file(file);
	fclose(file);
}


/**
 * read_file - reads a file
 * @file: pointer
 */

void read_file(FILE *file)
{
	int line_number, format = 0;
	char *line = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&line, &len, file) != -1; line_number++)
	{
		format = parseline(line, line_number, format);
	}
	free(line);
}


/**
 * parseline - Separates each line into tokens
 * @line: line from the file
 * @line_number: line number
 * @format:  storage format
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int parseline(char *line, int line_number, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (line == NULL)
		error1(4);

	opcode = strtok(line, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find(opcode, value, line_number, format);
	return (format);
}

/**
 * find - find the appropriate function
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue
 */
void find(char *opcode, char *value, int ln, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", push_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop},
		{"nop", nop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", div},
		{"mul", mul},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call(func_list[i].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		error1(3, ln, opcode);
}


/**
 * call - Calls the required function.
 * @func: Pointer to the function
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void call(op_func func, char *op, char *val, int ln, int format)
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
			error1(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				error1(5, ln);
		}
		node = create_node(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_queue(&node, ln);
	}
	else
		func(&head, ln);
}
