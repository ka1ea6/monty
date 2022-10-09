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