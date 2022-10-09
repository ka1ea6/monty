#include "monty.h"

/**
 * add_stack - adds the top two elements of the stack
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
 * sub_stack - subtracts the top element of the stack from the
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
 * mul_stack - multiplies the second top element of the stack with
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
	int product;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	product = 0;
	product += (*stack)->next->n;
	product *= (*stack)->n;

	(*stack)->next->n = product;
	(*stack)->next->prev = NULL;

	(*stack) = (*stack)->next;

}

/**
 * mod_stack - computes the rest of the division of the
 * second top element of the stack by the top element of
 * stack.
 *
 * @stack: pointer to the head of the stack
 * @line_number: line number.
 *
 * Return: Nothing.
 */

void mod_stack(stack_t **stack, unsigned int line_number)
{
	int res;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero", line_number);
		exit(EXIT_FAILURE);
	}
	res = 0;
	res += (*stack)->next->n;
	res %= (*stack)->n;

	(*stack)->next->n = res;
	(*stack)->next->prev = NULL;

	(*stack) = (*stack)->next;

}
