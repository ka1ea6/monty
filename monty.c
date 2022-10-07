#include "monty.h"

/**
 * main - starting point of the interpreter
 *
 * @argc: number of arguments passed.
 * @argv: vector containing arguments passed upon
 * execution.
 * Return: 0 if successful, 1 otherwise.
 */

int main(int argc, char *argv[])
{
	char *filename;
	FILE *file;

	if (argc < 2)
	{
		perror("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}


	filename = argv[1];
	file = fopen(filename, "r");
	if (!file)
	{
		printf("Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}


	parse_file(file);
	exit(EXIT_SUCCESS);
}

