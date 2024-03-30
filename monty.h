#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>

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
char **from_str_to_args(char *ptr);
void free_strings(char **grid);
char *_strdup(char *str);
void *_calloc(unsigned int nmemb, unsigned int size);
int _strcmp(char *s1, char *s2);
char **strtolines(char *ptr);
void set_null(char *s);
instruction_t *make_instructions(void);
void free_instruction(instruction_t *ptr);
int check_int(char *ptr);
void push_opcode(stack_t **stack, unsigned int line_number);
void pull_opcode(stack_t **stack, unsigned int line_number);
char **save_args(char **args);
void check_opcode(char *opcode, instruction_t *ins, char **lines);
void free_stack(stack_t *head);
void pint_opcode(stack_t **stack, unsigned int line_number);
void pop_opcode(stack_t **stack, unsigned int line_number);
int delete_dnodeint_at_index(stack_t **head, unsigned int index);
void swap_opcode(stack_t **stack, unsigned int line_number);
void nop_opcode(stack_t **stack, unsigned int line_number);
size_t stack_len(const stack_t *h);
void add_opcode(stack_t **stack, unsigned int line_number);
void sub_opcode(stack_t **stack, unsigned int line_number);
void div_opcode(stack_t **stack, unsigned int line_number);
void mul_opcode(stack_t **stack, unsigned int line_number);
void mod_opcode(stack_t **stack, unsigned int line_number);
void pchar_opcode(stack_t **stack, unsigned int line_number);
void pstr_opcode(stack_t **stack, unsigned int line_number);
void rotl_opcode(stack_t **stack, unsigned int line_number);
#endif/*endif*/
