#include "monty.h"

/**
 * add - adds the top two elements of the stack
 *
 * @stack: pointer to the head of the stack
 * @line_number: line number.
 *
 * Return: Nothing.
 */

void add(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = 0;
	sum += (*stack)->n;
	sum += (*stack)->next->n;

	(*stack)->next->n = sum;
	(*stack)->next->prev = NULL;

	(*stack) = (*stack)->next;

}

/**
 * sub - adds the top two elements of the stack
 *
 * @stack: pointer to the head of the stack
 * @line_number: line number.
 *
 * Return: Nothing.
 */

void sub(stack_t **stack, unsigned int line_number)
{
	int diff;

	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	diff = 0;
	diff += (*stack)->n;
	diff += (*stack)->next->n;

	(*stack)->next->n = diff;
	(*stack)->next->prev = NULL;

	(*stack) = (*stack)->next;

}
