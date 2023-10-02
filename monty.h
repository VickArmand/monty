#ifndef MONTY_H_
#define MONTY_H_
#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
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
 * struct shared - stores shared variables
 * @data: value to be pushed
 * @flag: flag for identifying queue and stack operations
 * @top: current top element of the stack
 * @fp: File pointer of open file(bytecode)
 * @line: string buffer
 * Description: shares values through out the program
 */
typedef struct shared
{
	char *data;
	int flag;
	stack_t *top;
	FILE *fp;
	char *line;
} shared_t;
extern shared_t s;
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
void free_stack(stack_t *stack);
void execute_instruction(char *line, unsigned int line_number,
		shared_t s, FILE *fp);
char *tokenize_instruction(char *line);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void divide(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void queue_add(stack_t *stack, int data);
void stack_add(stack_t *stack, int data);
#endif
