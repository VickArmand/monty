#include "monty.h"
/**
 * add - adds the top two elements of the stack
 * @stack: top element of the stack
 * @line_number: instruction line number in the bytecode
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	int sum;
	stack_t *current;

	if (*stack && (*stack)->next)
	{
		sum = (*stack)->n + (*stack)->next->n;
		(*stack)->next->n = sum;
		current = *stack;
		*stack = current->next;
		(*stack)->prev = NULL;
		s.top = *stack;
		free(current);
		(void)(line_number);
	}
	else
	{
		free_stack(*stack), free(s.line), fclose(s.fp);
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * sub - subtracts the top element of the stack
 * from the second top element of the stack.
 * @stack: top element of the stack
 * @line_number: instruction line number in the bytecode
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int minus;
	stack_t *current;

	if (*stack && (*stack)->next)
	{
		minus = (*stack)->n - (*stack)->next->n;
		if (minus < 0)
			minus *= -1;
		(*stack)->next->n = minus;
		current = *stack;
		*stack = current->next;
		(*stack)->prev = NULL;
		s.top = *stack;
		free(current);
		(void)(line_number);
	}
	else
	{
		free_stack(*stack), free(s.line), fclose(s.fp);
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * divide - divides the second top element of the stack
 * by the top element of the stack.
 * @stack: top element of the stack
 * @line_number: instruction line number in the bytecode
 * Return: void
 */
void divide(stack_t **stack, unsigned int line_number)
{
	int num;
	stack_t *current;

	if (*stack && (*stack)->next)
	{
		if ((*stack)->n != 0)
		{
			num = (*stack)->n / (*stack)->next->n;
			(*stack)->next->n = num;
			current = *stack;
			*stack = current->next;
			(*stack)->prev = NULL;
			s.top = *stack;
			free(current);
			(void)(line_number);
		}
		else
		{
			free_stack(*stack), free(s.line), fclose(s.fp);
			fprintf(stderr, "L%d: division by zero\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		free_stack(*stack), free(s.line), fclose(s.fp);
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * mul - multiplies the second top element of the stack
 * with the top element of the stack.
 * @stack: top element of the stack
 * @line_number: instruction line number in the bytecode
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int prod;
	stack_t *current;

	if ((*stack) && (*stack)->next)
	{
		prod = (*stack)->n * (*stack)->next->n;
		(*stack)->next->n = prod;
		current = *stack;
		*stack = current->next;
		(*stack)->prev = NULL;
		s.top = *stack;
		free(current);
		(void)(line_number);
	}
	else
	{
		free_stack(*stack), free(s.line), fclose(s.fp);
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack.
 * @stack: top element of the stack
 * @line_number: instruction line number in the bytecode
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int rem;
	stack_t *current;

	if ((*stack) && (*stack)->next)
	{
		if ((*stack)->n != 0)
		{
			rem = (*stack)->n % (*stack)->next->n;
			(*stack)->next->n = rem;
			current = *stack;
			*stack = current->next;
			(*stack)->prev = NULL;
			s.top = *stack;
			free(current);
			(void)(line_number);
		}
		else
		{
			free_stack(*stack), free(s.line), fclose(s.fp);
			fprintf(stderr, "L%d: division by zero\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		free_stack(*stack), free(s.line), fclose(s.fp);
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
