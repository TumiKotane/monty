#include "monty.h"

/**
 * add_to_queue - adds element to the queue
 * @new: pointer to new node
 * @line_num: line number
 */

void add_to_queue(stack_t **new, __attribute__((unused))unsigned int line_num)
{
	stack_t *temp;

	if (new == NULL || *new == NULL)
	exit(EXIT_FAILURE);

	if (head == NULL)
	{
		head = *new;
		return;
	}

	temp = head;

	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	temp->next = *new;
	(*new)->prev = temp;
}

/**
 * _push - adds an element to the stack
 * @new: pointer to new node
 * @line_num: line number
 */

void _push(stack_t **new, __attribute__((unused))unsigned int line_num)
{
	stack_t *temp;

	if (new == NULL || *new == NULL)
	exit(EXIT_FAILURE);

	if (head == NULL)
	{
		head = *new;
		return;
	}

	temp = head;
	head = *new;
	head->next = temp;
	temp->prev = head;
}

/**
 * _pall - adds element to stack
 * @stack: pointer to top of stack
 * @line_num: line number
 */

void _pall(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	(void) line_num;

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
 * _pint - prints element at top of stack
 * @stack: pointer to top element in stack
 * @line_num: line number
 */

void _pint(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL)
	err1(6, line_num);
	printf("%d\n", (*stack)->n);
}

/**
 * _pop - removes top element of stack
 * @stack: pointer to top element in stack
 * @line_num: line number
 */

void _pop(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	err1(7, line_num);

	temp = *stack;
	*stack = temp->next;

	if (*stack != NULL)
	(*stack)->prev = NULL;
	free(temp);
}
