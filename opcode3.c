#include "monty.h"

/**
 * add_opcode - adds the top two elements of the stack.
 *
 * @stack:Pointer to first node of list
 * @line_number: the number of line in file
 */
void add_opcode(stack_t **stack, unsigned int line_number)
{
	if (stack_len(*stack) < 2)
	{
		dprintf(stderr, "L%d: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n + (*stack)->n;
	delete_dnodeint_at_index(stack, 0);
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

	if (stack_len(*stack) < 2)
	{
		dprintf(stderr, "L%d: can't sub, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	i = (*stack)->next->n - (*stack)->n;
	(*stack)->next->n = i;
	delete_dnodeint_at_index(stack, 0);
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

	if (stack_len(*stack) < 2)
	{
		dprintf(stderr, "L%d: can't div, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	i = ((*stack)->next->n) / ((*stack)->n);
	(*stack)->next->n = i;
	delete_dnodeint_at_index(stack, 0);
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

	if (stack_len(*stack) < 2)
	{
		dprintf(stderr, "L%d: can't mul, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	i = (*stack)->next->n * (*stack)->n;
	(*stack)->next->n = i;
	delete_dnodeint_at_index(stack, 0);
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

	if (stack_len(*stack) < 2)
	{
		dprintf(stderr, "L%d: can't mod, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		dprintf(stderr, "L%d: division by zero\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	i = (*stack)->next->n % (*stack)->n;
	(*stack)->next->n = i;
	delete_dnodeint_at_index(stack, 0);
}
