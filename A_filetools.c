#include "monty.h"

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
 * @f_Des: it is a Pointer  that points to the
 * file descriptor.
 * Return: void
 */

void r_File(FILE *f_Des)
{
int line_number, formatFlag = 0;
char *buffer = NULL;
size_t buffer_s = 0;
for (line_number = 1; getline(&buffer, &buffer_s, f_Des) != -1; line_number++)
{
formatFlag = tokenizeLine(buffer, line_number, formatFlag);
}
free(buffer);
}

/**
 * tokenizeLine - Tokenizes a line into separate tokens to determine
 * which function to call.
 * @buffer: this is The line from the file.
 * @line_number: this is The line number.
 * @storageFormat: The storage format. If 0, nodes will be entered as a stack.
 * Return: Returns 0 if the opcode is "stack", 1 if "queue".
 */
int tokenizeLine(char *buffer, int line_number, int storageFormat)
{

	char *opcode, *token;
	const char *delimiter = "\n ";

	if (buffer == NULL)
		F_errorche(4);

	opcode = strtok(buffer, delimiter);
	if (opcode == NULL)
		return (storageFormat);
	token = strtok(NULL, delimiter);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	findFunction(opcode, token, line_number, storageFormat);
	return (storageFormat);
}
