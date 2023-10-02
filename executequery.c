#include "monty.h"
/**
 * execute_instruction - identifies the instruction and
 * executes the appropiate function
 * @line: instruction
 * @line_number: instruction line number
 * @s: shared variables structure
 * @fp: file pointer
 * Return: void
 */
void execute_instruction(char *line, unsigned int line_number,
		shared_t s, FILE *fp)
{
	char *token;
	int j, isfound = 0, isqueue = 0;
	instruction_t inst[] = {
		{"push", push}, {"pop", pop}, {"pall", pall},
		{"pint", pint}, {"swap", swap}, {"add", add},
		{"sub", sub}, {"divide", divide}, {"mul", mul},
		{"mod", mod}, {"pchar", pchar}, {"pstr", pstr},
		{"rotl", rotl}, {"rotr", rotr}, {"nop", nop},
		{NULL, NULL}
	};

	if (line[0] == '#')
		return;
	token = tokenize_instruction(line);
	if (strcmp(token, "queue") == 0)
		isqueue = 1, isfound = 1;
	else if (strcmp(token, "stack") == 0)
		isqueue = 0, isfound = 1;
	else
	{
		j = 0;
		while (inst[j].opcode != NULL)
		{
			if (strcmp(inst[j].opcode, token) == 0)
			{
				isfound = 1;
				inst[j].f(&(s.top), line_number);
				break;
			}
			j++;
		}
	}
	s.flag = isqueue;
	if (isfound == 0)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
		free_stack(s.top), free(line), fclose(fp), exit(EXIT_FAILURE);
	}
	(void)s;
	free_stack(s.top);
}
/**
 * tokenize_instruction - tokenizes a string and store it in an array
 * @line: string to tokenize
 * Return: a token
 */
char *tokenize_instruction(char *line)
{
	char *token = NULL;

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
