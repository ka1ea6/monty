#include "monty.h"

/**
 * add - adds the top two elements of the stack
 *
 * @stack: pointer to the head of the stack
 * @line_number: line number.
 *
 * Return: Nothing.
 */

void add_stack(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (!(*stack) || !(*stack)->next)
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
 * sub - subtracts the top element of the stack from the
 * second top element.
 *
 * @stack: pointer to the head of the stack
 * @line_number: line number.
 *
 * Return: Nothing.
 */

void sub_stack(stack_t **stack, unsigned int line_number)
{
	int diff;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	diff = 0;
	diff -= (*stack)->n;
	diff += (*stack)->next->n;

	(*stack)->next->n = diff;
	(*stack)->next->prev = NULL;

	(*stack) = (*stack)->next;

}

/**
 * div_stack - divides the second top element by the top
 * element of the stack
 *
 * @stack: pointer to the head of the stack
 * @line_number: line number.
 *
 * Return: Nothing.
 */

void div_stack(stack_t **stack, unsigned int line_number)
{
	int quotient;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero", line_number);
		exit(EXIT_FAILURE);
	}
	quotient = 0;
	quotient += (*stack)->next->n;
	quotient /= (*stack)->n;

	(*stack)->next->n = quotient;
	(*stack)->next->prev = NULL;

	(*stack) = (*stack)->next;

}

/**
 * mul - multiplies the second top element of the stack with
 * the top element of the stack
 *
 *
 * @stack: pointer to the head of the stack
 * @line_number: line number.
 *
 * Return: Nothing.
 */

void mul_stack(stack_t **stack, unsigned int line_number)
{
	int quotient;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero", line_number);
		exit(EXIT_FAILURE);
	}
	quotient = 0;
	quotient += (*stack)->next->n;
	quotient *= (*stack)->n;

	(*stack)->next->n = quotient;
	(*stack)->next->prev = NULL;

	(*stack) = (*stack)->next;

}
