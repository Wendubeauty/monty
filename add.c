#include "monty.h"

/**
 * op_add - Adds the top two elements of the stack.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Current line number in the bytecode file.
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	int i, j;
	stack_t *temp;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	i = (*stack)->n;
	j = (*stack)->next->n;
	(*stack)->n = i + j;

	temp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	if ((*stack)->next)
	{
		(*stack)->next->prev = *stack;
	}
	free(temp);
}
