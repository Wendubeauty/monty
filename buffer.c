#include "monty.h"

/**
 * _buffer - Read and process instructions from a bytecode file.
 * @file_name: Name of the bytecode file to read.
 */
void _buffer(char *file_name)
{
	FILE *file;
	char *str = NULL;
	char *command = NULL;
	unsigned int line_number = 1;
	size_t len = 0;
	stack_t *stack = NULL;

	file = fopen(file_name, "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	arg_con.file = file;
	while (getline(&str, &len, file) != -1)
	{
		arg_con.data = str;
		if (*str == '\n')
		{
			line_number++;
			continue;
		}
		command = strtok(str, " \t\n$");
		if (!command)
		{
			line_number++;
			continue;
		}
		arg_con.arg = strtok(NULL, " \t\n$");
		get_opcode(&stack, line_number, command);
		line_number++;
	}
	free_stk(&stack);
}
