#include "monty.h"

/**
 * pint - prints the first element of a stack
 *
 * @stack: pointer to the head of the stack.
 * @line_number: the line of the current instruction.
 *
 * Return: nothing.
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);

}
