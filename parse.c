#include "monty.h"

/**
 * parse_file - parses a file line by line
 *
 * @file - pointer to a file object.
 *
 * Return: Nothing.
 */

void parse_file(FILE *file)
{

	int j, line_number, fun_arr_length;
	char *line;
	char *token1, *token2;
	stack_t *head = NULL;
	instruction_t fun_arr[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add}
	};

	fun_arr_length = (int) sizeof(fun_arr)/sizeof(fun_arr[0]);
	line = malloc(sizeof(char) * 100);
	line_number = 1;
	while (fgets(line, 100, file))
	{
		token1 = strtok(line, " \t\r\n\v\f$;");
		token2 = strtok(NULL, " \t\r\n\v\f$;");

		if (token1)
		{
			j = 0;
			while (j < fun_arr_length && strcmp(token1, fun_arr[j].opcode) != 0)
				j++;
			if (j < fun_arr_length)
			{
				if (token2)
					fun_arr[j].f(&head, atoi(token2));
				else if (strcmp(fun_arr[j].opcode, "pall") == 0)
					fun_arr[j].f(&head, 0);
				else if (strcmp(fun_arr[j].opcode, "pint") == 0 || strcmp(fun_arr[j].opcode, "pop") == 0 || strcmp(fun_arr[j].opcode, "swap") == 0 || strcmp(fun_arr[j].opcode, "add") == 0)
					fun_arr[j].f(&head, line_number);
				line_number++;
			}
			else
			{
				free_stack(head);
				fprintf(stderr, "L<%d>: unknown instruction %s\n", line_number, token1);
				exit(EXIT_FAILURE);
			}
		}
	}

	free_stack(head);
	free(line);
	fclose(file);
}
