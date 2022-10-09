#include "monty.h"

/**
 * pall - prints all the elements found in the stack
 *
 * @stack: pointer to the head of the stack
 * @line_number: unused variable.
 *
 * Return: Nothing.
 */

void pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	size_t size;
	stack_t *temp;

	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	temp = *stack;

	size = 0;

	while (temp)
	{
		printf("%d\n", (temp)->n);
		(temp) = (temp)->next;
		size++;
	}
	free(temp);
}