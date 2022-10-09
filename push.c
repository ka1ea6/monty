#include "monty.h"

/**
 * push - pushes an element to the stack
 *
 * @stack: pointer to the head of the stack
 * @line_number: number found on the line
 *
 * Return: Nothing.
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));

	if (!new)
	{
		fprintf(stderr, "Error malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = line_number;
	new->prev = NULL;
	new->next = NULL;

	if ((*stack) != NULL)
	{
		new->next = (*stack);
		(*stack)->prev = new;
	}

	*stack = new;

}
