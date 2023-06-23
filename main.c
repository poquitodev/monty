#include "monty.h"
bs_t bs = {NULL, NULL, NULL, 0};
/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *content;
	FILE *fl;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fl = fopen(argv[1], "r");
	bs.fl = fl;
	if (!fl)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, fl);
		bs.content = content;
		line_number++;
		if (read_line > 0)
		{
			execute_fn(content, &stack, line_number, fl);
		}
		free(content);
	}
	stack_freeing(stack);
	fclose(fl);
return (0);
}
