#include "monty.h"

stack_t *head = NULL;

/**
 * make_node - for creating nodes
 * @n: number to go with node
 * Return: pointer to new node, NULL otherwise
 */

stack_t *make_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));

	if (node == NULL)
	err(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;

	return (node);
}

/**
 * free_nodes - frees nodes in stack
 */

void free_nodes(void)
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
 * main - opens monty script
 * @argc: number of arguments
 * @argv: argument vector
 * Return: Always 0
 */

int main(int argc, char **argv)
{
	if (argc < 2 || argc > 2)
	err(1);
	open_file(argv[1]);
	free_nodes();
	return (0);
}
