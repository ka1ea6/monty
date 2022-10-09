#include "monty.h"

/**
 * pop - removes the top element of the stack
 *
 * @stack: pointer to the head of the stack
 * @line_number: current line number.
 *
 * Return: Nothing.
 */

void pop(stack_t **stack, unsigned int line_number)
{

	stack_t *temp;

	printf("here too \n");
	if (!(*stack))
	{
		fprintf(stderr, "L<%d>: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;

	if (temp->next)
	{
		*stack = temp->next;
		(*stack)->prev = NULL;
	}
	else
		*stack = NULL;

	free(temp);
}