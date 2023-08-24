#include "monty.h"

/**
 * open_file - used to open files
 * @file: name of file to open
 */

void open_file(char *file)
{
	int check;
	FILE *fd;

	if (file == NULL)
	err(2, file);

	check = access(file, R_OK);

	if (check == -1)
	err(2, file);

	fd = fopen(file, "r");

	if (fd == NULL)
	err(2, file);

	file_reader(fd);

	fclose(fd);
}

/**
 * file_reader - reads content of file
 * @fd: pointer to file descriptor
 */

void file_reader(FILE *fd)
{
	int line_num, format = 0;
	char *line;
	size_t x = 0;

	line = NULL;

	if (fd == NULL)
	err(2, "file");

	for (line_num = 1; getline(&line, &x, fd) != EOF; line_num++)
	{
		format = tok_line(line, line_num, format);
	}
	free(line);
}

/**
 * tok_line - splits lines into tokens
 * @line: line in file
 * @line_num: opcode line number
 * @format: specifies format
 * Return: 0 if stack, 1 if queue
 */

int tok_line(char *line, int line_num, int format)
{
	char *val, *opcode;
	const char *delim;

	if (line == NULL)
	err(4);

	delim = "\n ";
	opcode = strtok(line, delim);

	if (opcode == NULL)
	return (format);

	val = strtok(NULL, delim);

	if (strcmp(opcode, "queue") == 0)
	return (1);

	else if (strcmp(opcode, "stack") == 0)
	return (0);

	check_func(opcode, val, line_num, format);

	return (format);
}
