#include "monty.h"

/**
 * push_stack - Adds a node to the stack.
 * @new_node - Pointer to the new node.
 * @ln: Interger
*/

void push_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}

	temp = head;
	head = *new_node;
	head->next = temp;
	temp->prev = head;
}

/**
 * print_stack - print stack
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: line number of  the opcode.
*/

void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;

	if (stack == NULL)
		exit(EXIT_FAILURE);
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
