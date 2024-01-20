#include "monty.h"
#include <stdio.h>

/**
 * openFile - this Opens a file specified by the file name path.
 * @fileName: The name of  file path.
 * Return: Returns void
 */

void openFile(char *fileName)
{
	FILE *fileDescriptor = fopen(fileName, "r");

	if (fileName == NULL || fileDescriptor == NULL)
		F_errorche(2, fileName);
	r_File(fileDescriptor);
	fclose(fileDescriptor);
}

/**
 * r_File - this will actually Read the lines from a file and
 * parses them.
 * @fileDescriptor: it is a Pointer  that points to the
 * file descriptor.
 * Return: void
 */

void r_File(FILE *fileDescriptor)
{
int line_number, formatFlag = 0;
char *buffer = NULL;
size_t bufferSize = 0;
for (line_number = 1; getline(&buffer, &bufferSize, fileDescriptor) != -1; line_number++)
{
formatFlag = tokenizeLine(buffer, line_number, formatFlag);
}
free(buffer);
}

/**
 * tokenizeLine - Tokenizes a line into separate tokens to determine
 * which function to call.
 * @line: this is The line from the file.
 * @lineNum: this is The line number.
 * @storageFormat: The storage format. If 0, nodes will be entered as a stack.
 * Return: Returns 0 if the opcode is "stack", 1 if "queue".
 */
int tokenizeLine(char *line, int lineNum, int storageFormat)
{
	char *token;
	const char *delimiter = "\n ";

	if (line == NULL)
		F_errorche(4);
	token = strtok(line, delimiter);
	while (token != NULL)
	{
		if (strcmp(token, "stack") == 0)
			return (0);
		if (strcmp(token, "queue") == 0)
			return (1);
		findFunction(token, strtok(NULL, delimiter), lineNum, storageFormat);
		token = strtok(NULL, delimiter);
	}
	return (storageFormat);
}
