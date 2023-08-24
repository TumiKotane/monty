#include "monty.h"

/**
 * _rotl - rotates the stack to the top
 * @stack: pointer to top element in stack
 * @line_num: line number
 */

void _rotl(stack_t **stack, __attribute__((unused))unsigned int line_num)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	return;

	temp = *stack;

	while (temp->next != NULL)
	temp = temp->next;

	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
 * _rotr - rotates the stack to the bottom
 * @stack: pointer to top element in stack
 * @line_num: line number
 */

void _rotr(stack_t **stack, __attribute__((unused))unsigned int line_num)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	return;

	temp = *stack;

	while (temp->next != NULL)
	temp = temp->next;

	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stack)->prev = temp;
	(*stack) = temp;
}
