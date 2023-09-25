#include "monty.h"
shared_t s = {NULL, 0};
/**
 * main - main function
 * @argc: number of arguments
 * @argv: array of strings
 * Return: 0
 */
int main(int argc, char **argv)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read = 0;
	stack_t *top = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, fp)) != -1)
	{
		line_number++;
		execute_instruction(line, line_number, s, fp, top);
	}
	free(line);
	fclose(fp);
	exit(EXIT_SUCCESS);
	return (0);
}
