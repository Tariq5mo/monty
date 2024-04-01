#include "monty.h"

/**
 * stack_opcode - prints the char at the top of the stack.
 *
 * @stack:Pointer to first node of list
 * @line_number: the number of line in file
 */
void stack_opcode(stack_t **stack, unsigned int line_number)
{
	(void)(stack);
	(void)(line_number);
	_stack("1");
}
/**
 * queue_opcode - prints the char at the top of the stack.
 *
 * @stack:Pointer to first node of list
 * @line_number: the number of line in file
 */
void queue_opcode(stack_t **stack, unsigned int line_number)
{
	(void)(stack);
	(void)(line_number);
	_stack("-1");
}
/**
 * _stack - hssjsj
 * @str: str
 * Return: euu
*/
int _stack(char *str)
{
	static int i = 1;

	if (!str)
		return (i);
	if (atoi(str) == 1)
		i = 1;
	else if (atoi(str) == -1)
		i = -1;
	return (i);
}
/**
 * add_dnodeint_end - Adds a new node at the end of a dlistint_t list.
 *
 * @head:Pointer to first node of list
 * @n: the node's value
 * Return: the address of the new element, or NULL if it failed
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new, **p = head;

	if (!head)
		return (NULL);
	new = malloc(sizeof(stack_t));/*create new node*/
	if (!new)
		return (NULL);
	new->n = n;
	new->prev = NULL;
	new->next = NULL;
	if (!(*head))/*case if the list is empty*/
		(*head) = new;
	else
	{
		for (; (*p)->next; p = &((*p)->next))
			;
		new->prev = *p;
		(*p)->next = new;
	}
	return (new);
}
