#include "monty.h"

/**
 * main - Entry point of the Monty interpreter program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	_buffer(argv[1]);
	fclose(arg_con.file);
	return (EXIT_SUCCESS);
}
