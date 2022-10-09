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

	if (_isalpha(token2[0]))
	{
		fprintf(stderr, "L%d: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}
	new->n = atoi(token2);
	new->prev = NULL;
	new->next = NULL;

	if ((*stack) != NULL)
	{
		new->next = (*stack);
		(*stack)->prev = new;
	}

	*stack = new;

}

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

/**
 * pop - removes the top element of the stack
 *
 * @stack: pointer to the head of the stack
 * @line_number: current line number.
 *
 * Return: Nothing.
 */

void pop(stack_t **stack, unsigned int line_number)
{

	stack_t *temp;

	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;

	if (temp->next)
	{
		*stack = temp->next;
		(*stack)->prev = NULL;
	}
	else
		*stack = NULL;

	free(temp);

}

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


