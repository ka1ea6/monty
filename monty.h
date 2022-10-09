#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


extern char *token2;

/* utilities */

void parse_file(char *filename);
void get_token(char *line, int *line_number, stack_t **head);
void get_op(char *token1, int *line_number,  stack_t **head);
int check_op(char *opcode);
void free_stack(stack_t *stack);

int _isalpha(int c);
/* stack ops */

void push(stack_t **stack, unsigned int);
void pop(stack_t **stack, unsigned int);
void pall(stack_t **stack, unsigned int);
void pint(stack_t **stack, unsigned int);
void swap(stack_t **stack, unsigned int);
void add(stack_t **stack, unsigned int);
void sub(stack_t **stack, unsigned int);
void div_stack(stack_t **stack, unsigned int);


#endif
