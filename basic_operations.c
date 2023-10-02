#include "monty.h"
/**
 * push - Adds an element to the top of the stack.
 * @stack: top element of the stack
 * @line_number: instruction line number in the bytecode
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	int data;

	data = atoi(s.data);
	if ((data == 0 && strcmp(s.data, "0") != 0) || s.data == NULL)
	{
		free_stack(*stack), free(s.line), fclose(s.fp);
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (s.flag == 1)
		queue_add(*stack, data);
	else
		stack_add(*stack, data);
}
/**
 * pall - prints all stack elements
 * @stack: top element of the stack
 * @line_number: instruction line number in the bytecode
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	current = *stack;
	if (current == NULL)
		return;
	while (current != NULL)
	{
		fprintf(stdout, "%d\n", (current->n));
		current = current->next;
	}
	(void)(line_number);
}
/**
 * pop - Removes the topmost element from the stack
 * @stack: top element of the stack
 * @line_number: instruction line number in the bytecode.
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;

	if (*stack != NULL)
	{
		current = *stack;
		if (current->next)
		{
			*stack = current->next;
			(*stack)->prev = NULL;
		}
		else
			*stack = NULL;
		s.top = *stack;
		free(current);
		(void)(line_number);
	}
	else
	{
		free_stack(*stack), free(s.line), fclose(s.fp);
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * pint - displays the value at the top of the stack
 * @stack: top element of the stack
 * @line_number: instruction line number in the bytecode
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL)
	{
		fprintf(stdout, "%d\n", ((*stack)->n));
		(void)(line_number);
	}
	else
	{
		free_stack(*stack), free(s.line), fclose(s.fp);
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * swap - swaps the top two elements of the stack
 * @stack: top element of the stack
 * @line_number: instruction line number in the bytecode
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *nxt;

	if (*stack && (*stack)->next)
	{
		current = *stack;
		nxt = (*stack)->next;
		current->next = nxt->next;
		nxt->next->prev = current;
		current->prev = nxt;
		nxt->next = current;
		s.top = nxt;
		(void)(line_number);
	}
	else
	{
		free_stack(*stack), free(s.line), fclose(s.fp);
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
