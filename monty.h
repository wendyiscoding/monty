#ifndef MONTY_H
#define MONTY_H
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define MY_DELIM " \t\r\n\a"

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct info_s - info
 * @flag: flag for stack or queue
 * @line: line from file
 * @fp: file pointer
 * @command: command
 */
typedef struct info_s
{
	int flag;
	char *line;
	FILE *fp;
	char *command;
} info_t;

info_t info;

/* err */
void errac(void);
void erropen(char *arg);
void errnomatch(stack_t **stack, unsigned int line_number);
void errpush(stack_t **stack, unsigned int line_number);
void errpint(stack_t **stack, unsigned int line_number);

/* err2 */
void errpop(stack_t **stack, unsigned int line_number);
void errswap(stack_t **stack, unsigned int line_number);
void erradd(stack_t **stack, unsigned int line_number);
void errsub(stack_t **stack, unsigned int line_number);
void errdiv(stack_t **stack, unsigned int line_number, int divcode);

/* err3 */
void errmul(stack_t **stack, unsigned int line_number);
void errmod(stack_t **stack, unsigned int line_number, int modcode);
void errpchar(stack_t **stack, unsigned int line_number, int pcharcode);

/* ops */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

/* ops2 */
void _add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);

/* ops3 */
void _mod(stack_t **stack, unsigned int line_number);
void _pchar(stack_t **stack, unsigned int line_number);
void _pstr(stack_t **stack, unsigned int line_number);
void _rotl(stack_t **stack, unsigned int line_number);
void _rotr(stack_t **stack, unsigned int line_number);

/* ops4 */
void _stack(stack_t **stack, unsigned int line_number);
void _queue(stack_t **stack, unsigned int line_number);

/* helper */
unsigned short get_op_func(stack_t **stack, unsigned int line_number);
void free_close(stack_t *stack);
int isdigits(char *number);

#endif
