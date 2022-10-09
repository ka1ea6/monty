#include "monty.h"


/**
 * pchar - prints the char at the top of the stack
 *
 * @stack: pointer to the head of the stack
 * @line_number: line number.
 *
 * Return: Nothing.
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	int num;

	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	num = (*stack)->n;

	if (num < 0 || num > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", num);

}

/**
 * pstr - prints the char at the top of the stack
 *
 * @stack: pointer to the head of the stack
 * @line_number: line number.
 *
 * Return: Nothing.
 */

void pstr(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	int num;
    stack_t *temp;
	char *str;

	if (!(*stack))
	{
        	printf("\n");
		return;
	}
	
	temp = malloc(sizeof(stack_t));

	if (!temp)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	str = malloc(sizeof(char) * stack_size(*stack));

	temp = *stack;

	num = 0;
	while(temp)
	{
		if (temp->n == 0 || temp->n < 0 || temp->n > 127)
		{
			str[num] = '\0';
			break;
		}
		else
		{
			str[num] = (char) temp->n;
			temp = temp->next;
			num++;
		}
	}

	printf("%s\n", str);

	free(temp);
	free(str);

}
