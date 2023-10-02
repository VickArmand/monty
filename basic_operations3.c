#include "monty.h"
/**
 * pchar - prints the char at the top of the stack
 * @stack: top element of the stack
 * @line_number: instruction line number in the bytecode
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	char i;

	if (*stack != NULL)
	{
		if ((*stack)->n >= 0 && (*stack)->n < 127)
		{
			i = (*stack)->n;
			fprintf(stdout, "%c\n", i);
			(void)(line_number);
		}
		else
		{
			free_stack(*stack), free(s.line), fclose(s.fp);
			fprintf(stderr, "L%d : can't pchar, value out of range\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		free_stack(*stack), free(s.line), fclose(s.fp);
		fprintf(stderr, "L%d : can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * pstr - prints the string starting at the top of the stack,
 * followed by a new line.
 * @stack: top element of the stack
 * @line_number: instruction line number in the bytecode
 * Return: void
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	char i;
	stack_t *current;

	if (*stack != NULL)
	{
		current = *stack;
		while (current != NULL)
		{
			if (current->n > 0 && current->n < 127)
			{
				i = current->n;
				fprintf(stdout, "%d\n", i);
				(void)(line_number);
			}
			else
				break;
			current = current->next;
		}
	}
}
/**
 * rotl - rotates the stack to the top.
 * @stack: top element of the stack
 * @line_number: instruction line number in the bytecode
 * Return: void
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *new_top;

	if (*stack != NULL)
	{
		current = *stack;
		new_top = (*stack)->next;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = *stack;
		(*stack)->next = NULL;
		(*stack)->prev = current;
		(*stack) = new_top;
		s.top = *stack;
		(void)(line_number);
	}
}
/**
 * rotr - rotates the stack to the bottom
 * @stack: top element of the stack
 * @line_number: instruction line number in the bytecode
 * Return: void
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (*stack != NULL)
	{
		current = *stack;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = *stack;
		current->prev->next = NULL;
		current->prev = NULL;
		*stack = current;
		s.top = *stack;
		(void)(line_number);
	}
}
/**
 * nop - doesn't do anything
 * @stack: top element of the stack
 * @line_number: instruction line number in the bytecode
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)(stack);
	(void)(line_number);
}
