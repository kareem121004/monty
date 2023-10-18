#include "monty.h"

/**
 * open_file - opens a file
 * @filename: the file name
*/

void open_file(char *filename)
{
	FILE *file = fopen(filename, "r");

	if (filename == NULL || file == NULL)
		fprintf(stderr, "Error: Can't open file %s\n", filename);

	readfile(file);
	fclose(file);
}

/**
 * readfile - reads a file
 * @file: pointer to file descriptor
*/

void readfile(FILE *file)
{
	char *line = NULL;
	size_t len = 0;
	int line_number, format = 0;

	for (line_number = 1; getline(&line, &len, file) != -1; line_number++)
		format = parse(line, line_number, format);
	free(line);
}

/**
 * parse - Separates each line into tokens
 * @line: line from the file
 * @line_number: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
*/

int parse(char *line, int line_number, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (line == NULL)
		fprintf(stderr, "Error: malloc failed\n");

	opcode = strtok(line, delim);

	if (opcode == NULL)
		return (format);

	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	execute(opcode, value, line_number, format);
	return (format);
}
