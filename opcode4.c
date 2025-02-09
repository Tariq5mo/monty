#include "monty.h"

/**
 * pchar_opcode - prints the char at the top of the stack.
 *
 * @stack:Pointer to first node of list
 * @line_number: the number of line in file
 */
void pchar_opcode(stack_t **stack, unsigned int line_number)
{
	/* Check if the stack is empty */
	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* Check if the value is within the ASCII range */
	if ((*stack)->n < 1 || (*stack)->n > 128)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	putchar((*stack)->n); /* Print the character */
	putchar('\n');
}
/**
 * pstr_opcode - prints the string starting at the top of the stack.
 *
 * @stack:Pointer to first node of list
 * @line_number: the number of line in file
 */
void pstr_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *h;

	(void)(line_number);
	/* If the stack is empty, print a newline and return */
	if (!(*stack))
	{
		fprintf(stderr, "\n");
		return;
	}
	/* Iterate through the stack and print the characters until out of range */
	for (h = (*stack); h; h = h->next)
	{
		if (h->n < 1 || h->n > 128)
			break;
		putchar(h->n);
	}
	putchar('\n');
}
/**
 * rotl_opcode - rotates the stack to the top.
 *
 * @stack:Pointer to first node of list
 * @line_number: the number of line in file
 */
void rotl_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *last;

	(void)(line_number);
	/* If the stack is empty or has only one element, return */
	if (!(*stack) || !((*stack)->next))
		return;
	temp = (*stack);				   /* Save the top element */
	(*stack)->next->prev = NULL;	   /* Set the second element as the new top */
	(*stack) = (*stack)->next;		   /* Update the stack pointer */
	for (last = (*stack); last->next;) /* Find the last element */
		last = last->next;
	temp->next = NULL; /* Set the next of the original top to NULL */
	temp->prev = last; /* Set the previous of the original top to the last */
	last->next = temp; /* Set the next of the last to the original top */
}
/**
 * rotr_opcode - rotates the stack to the bottom.
 *
 * @stack:Pointer to first node of list
 * @line_number: the number of line in file
 */
void rotr_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *last;

	(void)(line_number);
	/* If the stack is empty or has only one element, return */
	if (!(*stack) || !((*stack)->next))
		return;
	for (last = (*stack); last->next;) /* Find the last element */
		last = last->next;
	last->prev->next = NULL; /* Set the next of the second to last to NULL */
	last->prev = NULL;		 /* Set the previous of the last to NULL */
	(*stack)->prev = last;	 /* Set the previous of the first to the last */
	last->next = (*stack);	 /* Set the next of the last to the first */
	(*stack) = last;		 /* Update the stack pointer */
}
