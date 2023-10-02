#include "monty.h"
/**
 * queue_add - adds a node through the rear in a queue
 * @stack: the top element in the queue
 * @data: integer value to be inserted to the node
 * Return: void
 * When switching modes ie:queue and stack
 * The top of the stack becomes the front of the queue
 * The front of the queue becomes the top of the stack
*/
void queue_add(stack_t *stack, int data)
{
	stack_t *new_top, *current;

	new_top = malloc(sizeof(stack_t));
	if (new_top == NULL)
	{
		free(new_top), free_stack(stack), free(s.line), fclose(s.fp);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	printf("add");
	new_top->next = NULL;
	new_top->n = data;
	if (stack)
	{
		current = stack;
		while (current)
			current = current->next;
		current->next = new_top;
	}
	else
		s.top = new_top;
	new_top->prev = current;
}
