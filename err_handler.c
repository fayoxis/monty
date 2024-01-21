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
{	va_list ag;
	char *op;
	int l_num;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			l_num = va_arg(ag, int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l_num, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
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
        va_list ag;
	char *op;
	int l_num;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			l_num = va_arg(ag, unsigned int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", l_num, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
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
        va_list ag;
	int l_num;

	va_start(ag, error_code);
	l_num = va_arg(ag, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", l_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", l_num);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
