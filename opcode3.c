#include "monty.h"

/**
 * add_opcode - adds the top two elements of the stack.
 *
 * @stack:Pointer to first node of list
 * @line_number: the number of line in file
 */
void add_opcode(stack_t **stack, unsigned int line_number)
{
	/* Check if the stack has at least two elements */
	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n + (*stack)->n;
	/* Add the top two elements */
	delete_dnodeint_at_index(stack, 0); /* Delete the top element */
}
/**
 * sub_opcode - subs the top two elements of the stack.
 *
 * @stack:Pointer to first node of list
 * @line_number: the number of line in file
 */
void sub_opcode(stack_t **stack, unsigned int line_number)
{
	int i;

	/* Check if the stack has at least two elements */
	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	i = (*stack)->next->n - (*stack)->n; /* Subtract the top two elements */
	(*stack)->next->n = i;				 /* Store the result in the second element */
	delete_dnodeint_at_index(stack, 0);	 /* Delete the top element */
}
/**
 * div_opcode - divs the top two elements of the stack.
 *
 * @stack:Pointer to first node of list
 * @line_number: the number of line in file
 */
void div_opcode(stack_t **stack, unsigned int line_number)
{
	int i;

	/* Check if the stack has at least two elements */
	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	i = ((*stack)->next->n) / ((*stack)->n); /* Divide the top two elements */
	(*stack)->next->n = i;					 /* Store the result in the second element */
	delete_dnodeint_at_index(stack, 0);		 /* Delete the top element */
}
/**
 * mul_opcode - muls the top two elements of the stack.
 *
 * @stack:Pointer to first node of list
 * @line_number: the number of line in file
 */
void mul_opcode(stack_t **stack, unsigned int line_number)
{
	int i;

	/* Check if the stack has at least two elements */
	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	i = (*stack)->next->n * (*stack)->n; /* Multiply the top two elements */
	(*stack)->next->n = i;				 /* Store the result in the second element */
	delete_dnodeint_at_index(stack, 0);	 /* Delete the top element */
}
/**
 * mod_opcode - mods the top two elements of the stack.
 *
 * @stack:Pointer to first node of list
 * @line_number: the number of line in file
 */
void mod_opcode(stack_t **stack, unsigned int line_number)
{
	int i;

	/* Check if the stack has at least two elements */
	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	/* Check if the top element is zero */
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	i = (*stack)->next->n % (*stack)->n; /* Modulo the top two elements */
	(*stack)->next->n = i;				 /* Store the result in the second element */
	delete_dnodeint_at_index(stack, 0);	 /* Delete the top element */
}
