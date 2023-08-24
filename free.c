#include "monty.h"

/**
* free_stk - frees the memory in the stack
* @stack: the first node
*/
void free_stk(stack_t **stack)
{
	stack_t *tmp;

	if (!stack)
		return;
	free(arg_con.data);
	while (*stack != NULL)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
