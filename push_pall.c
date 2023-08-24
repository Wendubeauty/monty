#include "monty.h"

/**
 * op_push - Pushes an element onto the stack.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Current line number in the bytecode file.
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	if (!stack)
		exit(EXIT_FAILURE);
	if (!(isnum(arg_con.arg)))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_stk(stack);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stk(stack);
		exit(EXIT_FAILURE);
	}
	if (arg_con.stk_queue == 0)
		anna(stack, new_node);
	else
		anny(stack, new_node);
}

/**
 * op_pall - Prints all the values on the stack.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Current line number in the bytecode file.
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void)line_number;
	if (!*stack)
		return;
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
