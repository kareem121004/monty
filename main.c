#include "monty.h"

/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
*/

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	open_file(argv[1]);
	free_stack();
	return (0);
}

/**
 * free_stack - Frees nodes in the stack.
*/

void free_stack(void)
{
	stack_t *temp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

/**
 * create_node - Creates a node.
 * @n: Number in the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
*/

stack_t *create_node(int n)
{
	stack_t *newnode;

	newnode = malloc(sizeof(stack_t));

	if (newnode == NULL)
		fprintf(stderr, "Error: malloc failed\n");

	newnode->next = NULL;
	newnode->prev = NULL;
	newnode->n = n;

	return (newnode);
}

/**
 * add_queue - Adds a node to the queue.
 * @new_node: Pointer to the new node.
 * @ln: line number
*/

void add_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
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

	while (temp->next != NULL)
		tmp = tmp->next;
	temp->next = *new_node;
	(*new_node)->prev = temp;
}
