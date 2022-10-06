#include "main.h"
void parse_file(FILE *file)
{

	ssize_t nread;
	size_t len = 0;
	int j;
	char *line;
	char *token1, *token2;
	stack_t *head = NULL;
	instruction_t fun_arr[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint}
	};

	while ((nread = getline(&line, &len, file)) != -1)
	{
		token1 = strtok(line, " \t\r\n\v\f$");
		token2 = strtok(NULL, " \t\r\n\v\f$");

		if (token1)
		{
			j = 0;
			while(j < 2 && strcmp(token1, fun_arr[j].opcode) != 0)
			{
				j++;
			}
			if (j < 2)
			{
				if (token2)
					fun_arr[j].f(&head, atoi(token2));
				else if (strcmp(fun_arr[j].opcode, "pall") == 0)
					fun_arr[j].f(&head, 0);
			}
		}
	}

	free_stack(head);
	free(line);
	fclose(file);
}
