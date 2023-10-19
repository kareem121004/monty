#include "monty.h"


/**
 * push_stack - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @ln: Interger representing the line number
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
 * print_stack - prints a node.
 * @stack: Pointer
 * @line_number: line number
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pop_node - pop node.
 * @stack: Pointer
 * @line_number: Interger representing the line number of of the opcode.
 */
void pop_node(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
		error2(7, line_number);

	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * print_top - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		error2(6, line_number);
	printf("%d\n", (*stack)->n);
}
