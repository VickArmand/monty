#include "monty.h"
/**
 * execute_instruction - identifies the instruction and
 * executes the appropiate function
 * @line: instruction
 * @line_number: instruction line number
 * @s: shared variables structure
 * @fp: file pointer
 * @top: stack top
 * Return: void
 */
void execute_instruction(char *line, unsigned int line_number,
		shared_t s, FILE *fp, stack_t *top)
{
	char *argv;
	int j = 0, isfound = 0;
	instruction_t inst[] = {
		{"push", push},
		{"pop", pop},
		{"pall", pall},
		{"pint", pint},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"divide", divide},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"nop", nop},
		{NULL, NULL}
	};

	argv = tokenize_instruction(line);
	while (inst[j].opcode != NULL)
	{
		if (_strcmp(inst[j].opcode, argv) == 0)
		{
			if (_strcmp(argv, "queue") == 0)
				s.flag = 1;
			isfound = 1;
			inst[j].f(&top, line_number);
		}
		j++;
	}
	if (isfound == 0)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, argv);
		free_stack(top), free(line), fclose(fp);
		exit(EXIT_FAILURE);
	}
	(void)s;
}
/**
 * tokenize_instruction - tokenizes a string and store it in an array
 * @line: string to tokenize
 * Return: a token
 */
char *tokenize_instruction(char *line)
{
	char *token;

	token = strtok(line, " \n\t");
	s.data = strtok(NULL, " \n\t");
	return (token);
}
/**
 * free_stack - free entire stack
 * @stack: top of the stack
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *top;

	top = stack;
	while (top)
	{
		free(top);
		top = top->next;
	}
}
