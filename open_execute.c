#include "monty.h"

/**
 * open_file - opens file, calls read_file, and closes
 *
 * @filename: name/path of file to open
 *
 **/

void open_file(char *filename)
{
	int fileCheck;
	FILE *fileReader;

	if (filename == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		free_stack(&head);
		exit(EXIT_FAILURE);
	}

	fileCheck = access(filename, R_OK);
	if (fileCheck == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		free_stack(&head);
		exit(EXIT_FAILURE);
	}

	fileReader = fopen(filename, "r");
	if (fileReader == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		free_stack(&head);
		exit(EXIT_FAILURE);
	}

	read_file(fileReader);

	fclose(fileReader);
}

/**
 * read_file - Reads the input file line by line
 * sends each line into line tokenizer
 *
 * @fileReader: pointer to where information contained in file is stored
 */

void read_file(FILE *fileReader)
{
	int lineNum;
	char *line = NULL;
	size_t line_size = 0;

	for (lineNum = 1; getline(&line, &line_size, fileReader) != -1; lineNum++)
		tokenize_line(line, i);
}

/**
 * tokenize_line - tokenizes the current line to find current command
 *
 * @line: line of code to tokenize
 * @lineNum: line number currently tokenizing
 *
 * Return: Returns 1 on success
 */
int tokenize_line(char *line, int lineNum)
{
	char *func, *numValue;

	if (line == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(&head);
		exit(EXIT_FAILURE);
	}

	func = strtok(line, " \n\a\t");
	if (func == NULL)
		return (1);

	numValue = strtok(NULL, "\n\a\t");

	match_function(func, numValue, lineNum);

	return (1);
}

/**
 * match_function - matches func with correct function pointer
 *
 * @func: tokenized command found
 * @numValue: string of number to be added to node
 * @lineNum: current line number of input file
 */
void match_function(char *func, char *numValue, int lineNum)
{
	int i, flag = 1;
	instruction_t instruction[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	for (i = 0; instruction[i].opcode != NULL; i++)
	{
		if (strcmp(func, instruction[i].opcode) == 0)
		{
			execute_func(instruction[i].f, func, numValue, lineNum);
			flag = 0;
		}
	}

	if (flag == 1)
	{
		fprintf(stderr, "L%d: unkown instruction %s\n", lineNum, func);
		free_stack(&head);
		exit(EXIT_FAILURE);
	}
}


/**
 * execute_func - Executes correct function pointer
 *
 * @f: pointer to correct function
 * @func: string that was called
 * @numValue: string to be converted to number to insert
 * @lineNum: current line in the file being read
 */
void execute_func(op_func f, char *func, char *numValue, int lineNum)
{
	stack_t *newNode;
	int flag = 1, i;

	if (strcmp(func, "push") == 0)
	{
		if (numValue == NULL)
		{
		fprintf(stderr, "L%d: usage: push integer\n", lineNum);
		free_stack(&head);
		exit(EXIT_FAILURE);
		}

		if (numValue[0] == "-")
		{
			numValue = numValue + 1;
			flag *= -1;
		}

		for (i = 0; numValue[i] != '\0'; i++)
		{
			if (isdigit(numValue[i] == 0))
			{
				fprintf(stderr, "L%d: usage: push integer\n", lineNum);
				free_stack(&head);
				exit(EXIT_FAILURE);
			}
		}
		newNode = addNewNode(atoi(numValue) * flag);
		f(&newNode, lineNum);
	}
	else
		f(&head, lineNum);
}
