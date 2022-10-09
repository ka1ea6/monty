#include "monty.h"

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
	char *token1, *token2;

	token1 = strtok(line, " \t\r\n\v\f$;");
	token2 = strtok(NULL, " \t\r\n\v\f$;");

	get_op(token1, token2, line_number, head);
}

/**
 * get_op - gets the operation based on the token passed.
 *
 * @token1: string containing the first token.
 * @token2: string containing the second token
 * @line_number: pointer to the current line number
 * @head: pointer to the address of the head of the stack.
 *
 * Return: Nothing.
 */

void get_op(char *token1, char *token2, int *line_number,  stack_t **head)
{
	int j;
	instruction_t fun_arr[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add}
	};

	if (token1)
	{
		j = 0;
		while (j < fun_arr_length && strcmp(token1, fun_arr[j].opcode) != 0)
			j++;
		if (j < fun_arr_length)
		{
			if (token2 && atoi(token2) != 0)
				fun_arr[j].f(head, atoi(token2));
			else if (check_op(fun_arr[j].opcode))
				fun_arr[j].f(head, (*line_number));
			(*line_number)++;
		}
		else if (strcmp(token1, "nop") == 0)
		{
			(*line_number)++;
			continue;
		}
		else
		{
			free_stack(head);
			fprintf(stderr, "L<%d>: unknown instruction %s\n", line_number, token1);
			exit(EXIT_FAILURE);
		}
	}
}

/**
* check_op - checks type o fop for type of arg passed.
* 
* @opcode: opcode to be checked.
* 
* Return: 1 if opcode in switch, 0 otherwise.
*/

int check_op(char *opcode)
{
	switch(opcode)
	{
		case "pint":
		case "pop":
		case "swap":
		case "add":
			return 1;
		default:
			return 0;
	}
}