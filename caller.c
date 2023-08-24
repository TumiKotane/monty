#include "monty.h"

/**
 * check_func - checks for function to run the instructions
 * @opcode: operation code
 * @val: value for the opcode
 * @line_num: line number
 * @format: specifies format
 */

void check_func(char *opcode, char *val, int line_num, int format)
{
	int x, tag;

	instruction_t functions[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
	return;

	for (tag = 1, x = 0; functions[x].opcode != NULL; x++)
	{
		if (strcmp(opcode, functions[x].opcode) == 0)
		{
			call_func(functions[x].f, opcode, val, line_num, format);
			tag = 0;
		}
	}
	if (tag == 1)
	err(3, line_num, opcode);
}

/**
 * call_func - for calling needed function
 * @func: pointer to required function
 * @opcode: operating code
 * @val: value for opcode
 * @line_num: line number
 * @format: specifies format
 */

void call_func(op_func func, char *opcode, char *val, int line_num, int format)
{
	int x, tag;
	stack_t *node;

	tag = 1;

	if (strcmp(opcode, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val += 1;
			tag = -1;
		}

		if (val == NULL)
		err(5, line_num);

		for (x = 0; val[x] != '\0'; x++)
		{
			if (isdigit(val[x]) == 0)
			err(5, line_num);
		}

		node = make_node(atoi(val) * tag);

		if (format == 0)
		func(&node, line_num);

		if (format == 1)
		add_to_queue(&node, line_num);
	}
	else
		func(&head, line_num);
}
