#include "monty.h"

/**
 * F_errorche - it Prints appropriate error messages based on the error code.
 * @error_code: The error code determines the following type of error:
 * No file or multiple files provided to the program.
 * Unable to open or read the provided file.
 * Invalid instruction found in the file.
 * Failed to allocate memory.
 * Non-integer parameter passed to the "push" instruction.
 * Empty stack encountered during "pint" operation.
 * Empty stack encountered during "pop" operation.
 * Stack is too short for the operation.
 */
void F_errorche(int error_code, ...)
{
	va_list args;

	va_start(args, error_code);

	if (error_code == 1)
	{
		fprintf(stderr, "USAGE: monty file\n");
	}
	else if (error_code == 2)
	{
		fprintf(stderr, "Error: Can't open file %s\n", va_arg(args, char *));
	}
	else if (error_code == 3)
	{
		int line_num = va_arg(args, int);
		char *op = va_arg(args, char *);

		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, op);
	}
	else if (error_code == 4)
	{
		fprintf(stderr, "Error: malloc failed\n");
	}
	else if (error_code == 5)
	{
		fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
	}

	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * handleErrors - Function that handles errors in the program.
 *
 * @errorCode: The error codes and their meanings are as follows:
 * Error1: Empty stack when 'pint' is called.
 * Error2: Empty stack when 'pop' is called.
 * Error3: Stack is too short for the operation.
 * Error4: Division by zero.
 */
void handleErrors(int errorCode, ...)
{
	va_list args;
	char *operation;
	int line_num;

	va_start(args, errorCode);

	if (errorCode == 6)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(args, int));
	}
	else if (errorCode == 7)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(args, int));
	}
	else if (errorCode == 8)
	{
		line_num = va_arg(args, unsigned int);
		operation = va_arg(args, char*);
		fprintf(stderr, "L%d: can't %s, stack too short\n", line_num, operation);
	}
	else if (errorCode == 9)
	{
		fprintf(stderr, "L%d: division by zero\n", va_arg(args, unsigned int));
	}

	va_end(args);
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * handleStr_Errors - Handles errors in the string processing function.
 *
 * This function is responsible for handling errors
 * that occur suring string processing
 * @errorCode: The error codes are as follows:
 * The which is number inside a node is outside the ASCII bounds.
 * The stack is totally empty.
 */
void handleStr_Errors(int errorCode, ...)
{
	va_list args;
	int line_num;

	va_start(args, errorCode);
	line_num = va_arg(args, int);

	if (errorCode == 10)
	{
		fprintf(stderr, "Line %d: Cannot process character, value is out of range\n",
				line_num);
	}
	else if (errorCode == 11)
	{
		fprintf(stderr, "Line %d: Cannot process character, stack is empty\n",
				line_num);
	}

	free_nodes();
	exit(EXIT_FAILURE);
}
