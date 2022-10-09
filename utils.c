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

/**
 * stack_size - gets the size of a stack.
 *
 * @stack: pointer to stack to be freed.
 *
 * Return: size of the stack if successful, -1 otherwise.
 */

int stack_size(stack_t *stack)
{
	stack_t *temp;
	int size;

	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	temp = (stack);
	size = 0;
	while (temp)
	{
		temp = temp->next;
		size++;
	}

	return (size);
}


/**
 * _isalpha - shows 1 if the input is an alphabet,
 * all other characters result in printing of 0
 *
 * @c: The ASCII code of the character
 *
 * Return: 1 for alphabet. 0 for the rest.
 */
int _isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
