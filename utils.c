#include "monty.h"

/**
 * free_stack - frees a stack pointed by stack.
 *
 * @stack: pointer to stack to be freed.
 *
 * Return: Nothing.
 */

void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
