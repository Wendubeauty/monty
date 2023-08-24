#include "monty.h"

/**
 * op_pop - Removes the top element of the stack.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Current line number in the bytecode file.
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_stk(stack);
		exit(EXIT_FAILURE);
	}
	if (!tmp->next)
	{
		free(*stack);
		*stack = NULL;
	}
	else
	{
		(*stack) = (*stack)->next;
		(*stack)->prev = NULL;
		free(tmp);
	}
}
