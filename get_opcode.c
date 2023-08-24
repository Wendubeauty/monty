#include "monty.h"

/**
 * get_opcode - Find and execute the appropriate opcode function.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Current line number in the bytecode file.
 * @command: The opcode command to execute.
 */
void get_opcode(stack_t **stack, unsigned int line_number, char *command)
{
	int input = 0;

	instruction_t codes[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{"\0", NULL}
	};

	while (codes[input].opcode != NULL)
	{
		if (strcmp(codes[input].opcode, command) == 0)
		{
			codes[input].f(stack, line_number);
			return;
		}
		input++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, command);
	free_stk(stack);
	exit(EXIT_FAILURE);
}
