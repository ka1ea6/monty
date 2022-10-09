#include "monty.h"

char *token2 = NULL;

/**
 * parse_file - parses a file line by line
 *
 * @filename: string containing the name of the file to be
 * parsed.
 *
 * Return: Nothing.
 */

void parse_file(char *filename)
{
	FILE *file;
	char *line;
	int line_number;
	stack_t *head = NULL;

	file = fopen(filename, "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	line = malloc(sizeof(char) * 100);
	line_number = 1;

	while (fgets(line, 100, file))
	{
		get_token(line, &line_number, &head);
	}
}

/**
 * get_token - gets the tokens from the parsed file
 *
 * @line: string containing the parsed line.
 * @line_number: pointer to the current line number
 * @head: pointer to the address of the head of the stack.
 *
 * Return: Nothing.
 */

void get_token(char *line, int *line_number, stack_t **head)
{
	char *token1;

	token1 = strtok(line, " \t\r\n\v\f$;");
	token2 = strtok(NULL, " \t\r\n\v\f$;");

	get_op(token1, line_number, head);
}

/**
 * get_op - gets the operation based on the token passed.
 *
 * @token1: string containing the first token.
 * @line_number: pointer to the current line number
 * @head: pointer to the address of the head of the stack.
 *
 * Return: Nothing.
 */

void get_op(char *token1, int *line_number,  stack_t **head)
{
	int j, fun_arr_length;

	instruction_t fun_arr[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop}, {"swap", swap},
		{"add", add_stack}, {"sub", sub_stack}, {"div", div_stack}, {"div", mul_stack},
		{"mod", mod_stack},
	};

	fun_arr_length = (int) sizeof(fun_arr) / sizeof(fun_arr[0]);
	if (token1)
	{
		j = 0;
		while (j < fun_arr_length && strcmp(token1, fun_arr[j].opcode) != 0)
			j++;
		if (j < fun_arr_length)
		{
			fun_arr[j].f(head, (*line_number));
			(*line_number)++;
		}
		else if (strcmp(token1, "nop") == 0)
		{
			(*line_number)++;
		}
		else
		{
			free_stack(*head);
			fprintf(stderr, "L%d: unknown instruction %s\n", *line_number, token1);
			exit(EXIT_FAILURE);
		}
	}
	else
		(*line_number)++;
}
