#include "monty.h"

/**
 * isnum - Checks if a string represents a valid integer.
 * @str: The input string to check.
 * Return: 1 if the string is a valid number, 0 if it is not
 */
int isnum(char *str)
{
	if (str == NULL || *str == '\0')
		return (0);
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

/**
 * anna - The master of stacks in League of Legends
 * @stack: the stack memory
 * @new_node: the new memory to be added
 */
void anna(stack_t **stack, stack_t *new_node)
{
	new_node->n = atoi(arg_con.arg);
	if (!*stack)
	{
		new_node->prev = NULL;
		new_node->next = NULL;
		*stack = new_node;
	}
	else
	{
		(*stack)->prev = new_node;
		new_node->next = *stack;
		new_node->prev = NULL;
		*stack = new_node;
	}
}

/**
 * anny - Adds a new element to the end of the stack
 * @stack: the stack memory
 * @new_node: the new memory node to be added
 */
void anny(stack_t **stack, stack_t *new_node)
{
	stack_t *tmp;

	new_node->next = NULL;
	new_node->n = atoi(arg_con.arg);
	if (!*stack)
	{
		new_node->prev = NULL;
		*stack = new_node;
	}
	else
	{
		tmp = *stack;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_node;
		new_node->prev = tmp;
	}
}
