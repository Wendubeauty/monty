#ifndef _MONTY_H_
#define _MONTY_H_

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

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
 * struct glob_struct - contain global variables
 * @arg: arguments
 * @data: the input data
 * @stk_queue: the stack or the queue
 * @file: the file
 */
typedef struct glob_struct
{
	char *arg;
	char *data;
	int stk_queue;
	FILE *file;
} glob_var;

extern glob_var arg_con;
glob_var arg_con;

int isnum(char *str);
void free_stk(stack_t **stack);
void get_opcode(stack_t **stack, unsigned int line_number, char *command);
void _buffer(char *file_name);
void op_push(stack_t **stack, unsigned int line_number);
void op_pall(stack_t **stack, unsigned int line_number);
void op_pint(stack_t **stack, unsigned int line_number);
void op_pop(stack_t **stack, unsigned int line_number);
void op_swap(stack_t **stack, unsigned int line_number);
void op_nop(stack_t **stack, unsigned int line_number);
void op_add(stack_t **stack, unsigned int line_number);
void anna(stack_t **stack, stack_t *new_node);
void anny(stack_t **stack, stack_t *new_node);

#endif /* _MONTY_H_ */
