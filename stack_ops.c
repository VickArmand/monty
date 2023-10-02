#include "monty.h"
/**
 * stack_add - adds an element at the top of the stack
 * @stack: element at the top of the stack
 * @data: integer value to be inserted to the node
*/
void stack_add(stack_t *stack, int data)
{
	stack_t *new_top;

	new_top = malloc(sizeof(stack_t));
	if (new_top == NULL)
	{
		free(new_top), free_stack(stack), free(s.line), fclose(s.fp);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (stack)
		stack->prev = new_top;
	new_top->next = stack;
	new_top->n = data;
	new_top->prev = NULL;
	s.top = new_top;
}
