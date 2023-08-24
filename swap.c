#include "monty.h"

/**
 * op_swap - Swaps the top two elements of the stack.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Current line number in the bytecode file.
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if ((*stack)->next == NULL || *stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stk(stack);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}
