#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stddef.h>
#include <ctype.h>
#include <string.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
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
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct glob - global variable structure
 * @buffer: the buffer to store lines
 * @tok1: the opcode from line
 * @tok2: the second token as string converted to number with atoi
 * @tok3: the second token as string before conversion
 * @fd: the file opened
 * Description: the global variable structure
 *
 */
typedef struct glob
{
	char *buffer;
	char *tok1;
	int tok2;
	char *tok3;
	FILE *fd;
} global;

extern global global_var;

void (*compare(char *token))(stack_t **stack, unsigned int line_number);
void tok(stack_t **stack, unsigned int line_number, char *buffer);
int isnumber(char *token);
void msg_error(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void free_stack(stack_t **stack);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void ad(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
#endif
