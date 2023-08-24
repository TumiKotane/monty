#include "monty.h"

/**
 * _swap - swaps the top two elements of stack
 * @stack: poiter to top element in stack
 * @line_num: line number
 */

void _swap(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	err1(8, line_num, "swap");

	temp = (*stack)->next;
	(*stack)->next = temp->next;

	if (temp->next != NULL)
	temp->next->prev = *stack;

	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}

/**
 * _add - adds two top elements of stack
 * @stack: pointer to top element in stack
 * @line_num: line number
 */

void _add(stack_t **stack, unsigned int line_num)
{
	int tot;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	err1(8, line_num, "add");

	(*stack) = (*stack)->next;
	tot = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = tot;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * _nop - does nothing
 * @stack: pointer to top element in stack
 * @line_num: line number
 */

void _nop(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}

/**
 * _sub - subtracts top element from second top element in stack
 * @stack: pointer to top element in stack
 * @line_num: line number
 */

void _sub(stack_t **stack, unsigned int line_num)
{
	int tot;

	if (stack == NULL || *stack == NULL || (*stack) == NULL)
	err1(8, line_num, "sub");

	(*stack) = (*stack)->next;
	tot = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = tot;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * _div - divides the second top element by the top element of the stack
 * @stack: pointer to top element in stack
 * @line_num: line number
 */

void _div(stack_t **stack, unsigned int line_num)
{
	int tot;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	err1(8, line_num, "div");

	(*stack) = (*stack)->next;
	tot = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = tot;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
