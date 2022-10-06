#include "main.h"

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));

	if (!new)
		return;
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

void pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	size_t size;
	stack_t *temp;

	temp = malloc(sizeof(stack_t));
	temp = *stack;

	size = 0;

	while(temp)
	{
		printf("%d\n", (temp)->n);
		(temp) = (temp)->next;
		size++;
	}
	free(temp);
}

void pint(__attribute__((unused))stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	printf("here at pint\n");
}
