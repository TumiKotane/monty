#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
  * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;

typedef void (*op_func)(stack_t **, unsigned int);

void err(int code, ...);
void err1(int code, ...);
void err2(int code, ...);
void check_func(char *opcode, char *val, int line_num, int format);
void call_func(op_func func, char *opcode, char *val, int line_num, int format);
void add_to_queue(stack_t **new, __attribute__((unused))unsigned int line_num);
void _push(stack_t **new, __attribute__((unused))unsigned int line_num);
void _pall(stack_t **stack, unsigned int line_num);
void _pint(stack_t **stack, unsigned int line_num);
void _pop(stack_t **stack, unsigned int line_num);
void _swap(stack_t **stack, unsigned int line_num);
void _add(stack_t **stack, unsigned int line_num);
void _nop(stack_t **stack, unsigned int line_num);
void _sub(stack_t **stack, unsigned int line_num);
void _div(stack_t **stack, unsigned int line_num);
void _mul(stack_t **stack, unsigned int line_num);
void _mod(stack_t **stack, unsigned int line_num);
void _pchar(stack_t **stack, unsigned int line_num);
void _pstr(stack_t **stack, __attribute__((unused))unsigned int line_num);
void _rotl(stack_t **stack, __attribute__((unused))unsigned int line_num);
void _rotr(stack_t **stack, __attribute__((unused))unsigned int line_num);
stack_t *make_node(int x);
void free_nodes(void);
int main(int argc, char **argv);
void open_file(char *file);
void file_reader(FILE *fd);
int tok_line(char *line, int line_num, int format);
#endif
