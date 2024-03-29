#include "monty.h"

/**
 * pop_opcode - removes the top element of the stack.
 *
 * @stack:Pointer to first node of list
 * @line_number: the number of line in file
 */
void pop_opcode(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		dprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	delete_dnodeint_at_index(stack, 0);
}
/**
 * delete_dnodeint_at_index - delete a node at a given position.
 *
 * @head:Pointer to first node of list
 * @index:the index of the node
 * Return: 1 on Success, -1 on failure
 */
int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *pp, **p;

	if (!head && !(*head))
		return (-1);
	for (p = head; index > 0 && *p && (*p)->next; p = &((*p)->next))
		index--;
	if (!(*p) && index > 0)/*check if valid*/
		return (-1);
	if ((*p)->next)
		(*p)->next->prev = (*p)->prev;
	pp = (*p)->next;
	free(*p);
	(*p) = pp;
	return (1);
}
/**
 * stack_len - return tge number of elements of a stack list.
 *
 * @h:Pointer to first node of list
 * Return: the number of nodes
 */
size_t stack_len(const stack_t *h)
{
	size_t i;

	for (i = 0; h; h = h->next)
		i++;
	return (i);
}
/**
 * swap_opcode - swaps the top two elements of the stack.
 *
 * @stack:Pointer to first node of list
 * @line_number: the number of line in file
 */
void swap_opcode(stack_t **stack, unsigned int line_number)
{
	if (stack_len(*stack) < 2)
	{
		dprintf(stderr, "L%d: can't swap, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->prev = (*stack)->prev;
	(*stack)->prev = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	if ((*stack)->prev->next)
		(*stack)->prev->next->prev = (*stack);
	(*stack)->prev->next = (*stack);
	(*stack) = (*stack)->prev;
}
/**
 * nop_opcode - doesn’t do anything.
 *
 * @stack:Pointer to first node of list
 * @line_number: the number of line in file
 */
void nop_opcode(stack_t **stack, unsigned int line_number)
{
	(void)(stack);
	(void)(line_number);
}
