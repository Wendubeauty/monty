#include "monty.h"

/**
 * op_add - Adds the top two elements of the stack.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Current line number in the bytecode file.
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	int i, j;

	if (!(*stack)->next || !*stack || !stack)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n",
			line_number);
		free_stk(stack);
		exit(EXIT_FAILURE);
	}
	i = (*stack)->n;
	j = (*stack)->next->n;
	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
	(*stack)->n = i + j;
}
