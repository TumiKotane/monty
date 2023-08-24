#include "monty.h"

/**
 * _mul - multiplies the second top element with top element of the stack
 * @stack: pointer to top element in stack
 * @line_num: line number
 */

void _mul(stack_t **stack, unsigned int line_num)
{
	int tot;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	err1(8, line_num, "mul");

	(*stack) = (*stack)->next;
	tot = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = tot;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * _mod - computes remainder of division
 * @stack: pointer to top element in stack
 * @line_num: line number
 */

void _mod(stack_t **stack, unsigned int line_num)
{
	int tot;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	err1(8, line_num, "mod");

	if ((*stack)->n == 0)
	err1(9, line_num);

	(*stack) = (*stack)->next;
	tot = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = tot;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * _pchar - prints char at top of stack
 * @stack: pointer to top element in stack
 * @line_num: line number
 */

void _pchar(stack_t **stack, unsigned int line_num)
{
	int alph;

	if (stack == NULL || *stack == NULL)
	err2(11, line_num);

	alph = (*stack)->n;

	if (alph < 0 || alph > 127)
	err2(10, line_num);
	printf("%c\n", alph);
}

/**
 * _pstr - prints string at top of stack
 * @stack: pointer to top element in stack
 * @line_num: line number
 */

void _pstr(stack_t **stack, __attribute__((unused))unsigned int line_num)
{
	int alph;
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	temp = *stack;

	while (temp != NULL)
	{
		alph = temp->n;

		if (alph <= 0 || alph > 127)
		break;
		printf("%c", alph);

		temp = temp->next;
	}
	printf("\n");
}
