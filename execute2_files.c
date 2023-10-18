#include "monty.h"

/**
 * execute - find the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @line_num: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
*/

void execute(char *opcode, char *value, int line_num, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", push_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
                return;
        for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
        {
                if (strcmp(opcode, func_list[i].opcode) == 0)
                {
                        call(func_list[i].f, opcode, value, line_num, format);
                        flag = 0;
                }
        }

        if (flag == 1)
                err(3, line_num, opcode);
}

/**
 * call - Calls the required function.
 * @func: Pointer to the function
 * @op: string
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
*/

void call(opcode_func func, char *op, char *val, int ln, int format)
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
			err(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				err(5, ln);
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
