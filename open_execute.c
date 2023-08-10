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
		exit(EXIT_FAILURE);
	}

	fileCheck = access(filename, R_OK);
	if (fileCheck == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	fileReader = fopen(filename, "r");
	if (fileReader == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
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
		exit(EXIT_FAILURE);
	}

	func = strtok(line, " \n\a\t");
	if (func == NULL)
		return (1);

	numValue = strtok(NULL, "\n\a\t");

	match_function(func, numValue, lineNum);

	return (1);
}

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
		{"nop", nop}
	};



}
