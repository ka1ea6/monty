#include "monty.h"


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

void pchar(stack_t **stack, unsigned int line_number)
{
	int num;

	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	
    num = atoi(token2)

    if (num < 0 || num > 127)
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
        exit(EXIT_FAILURE);
    }
	
    printf("%c", num);

}