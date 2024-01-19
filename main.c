#include "monty.h"
stack_t *head = NULL;

/**
 * main - entry point
 * @argc: thi is the arguments count
 * @argv: list of arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	openFile(argv[1]);
	free_nodes();

	return (0);
}
