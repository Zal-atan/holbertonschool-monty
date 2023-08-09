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
	int i;
	char *line = NULL;
	size_t line_size = 0;

	for (i = 1; getline(&line, &line_size, fileReader) != -1; i++)
		tokenizeLine()
}