#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 *
 * @stack: pointer to the top of the stack
 * @line_number: line number.
 *
 * Return: Nothing.
 */

void swap(stack_t **stack, unsigned int line_number)
{

	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->prev = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	(*stack)->prev->next = (*stack);
	(*stack)->prev->prev = NULL;

	(*stack) = (*stack)->prev;

}
