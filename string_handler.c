#include "monty.h"

/**
 * printAsciiValue - Prints the ASCII value of the top element in the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Unsigned integer representing the line number of the opcode.
 */
void printAsciiValue(stack_t **stack, unsigned int line_number)
{
	int asciiValue;
	stack_t *currentNode = *stack;

	/* Check if the stack is empty */
	if (stack == NULL || *stack == NULL)
		handleStr_Errors(11, line_number);
	/* Traverse the stack to find the top element */
	while (currentNode->next != NULL)
	{
		currentNode = currentNode->next;
	}
	asciiValue = currentNode->n;
	/* Check if the ASCII value is within the valid range */
	if (asciiValue < 0 || asciiValue > 127)
		handleStr_Errors(10, line_number);
	/* Print the ASCII character */
	printf("%c\n", asciiValue);
}
/**
 * printString - Prints a string stored in the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNum: The line number of the opcode (unused in this function).
 */
void printString(stack_t **stack, __attribute__((unused))
unsigned int lineNum)
{
	int asciiValue;
	stack_t *tmpNode;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}
	tmpNode = *stack;
	do {
		asciiValue = tmpNode->n;
		if (asciiValue <= 0 || asciiValue > 127)
			break;
		printf("%c", asciiValue);
		tmpNode = tmpNode->next;
	} while (tmpNode != NULL);
		printf("\n");
}

/**
 * rotateFirstToBottom - Moves the first node of the stack
 * to the bottom, effectively rotating the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNum: The line number of the opcode (unused).
 */
void rotateFirstToBottom(stack_t **stack, __attribute__((unused))
unsigned int lineNum)
{
	stack_t *current;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	current = *stack;
	while (current->next != NULL)
		current = current->next;
	current->next = *stack;
	(*stack)->prev = current;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
 * rotateStackTop - Moves the last node of the stack to
 * the top, effectively rotating the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNum: The line number of the opcode (unused).
 */
void rotateStackTop(stack_t **stack, __attribute__((unused))
unsigned int lineNum)
{
	stack_t *lastNode = *stack;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	/* Find the last node of the stack */
	while (lastNode->next != NULL)
		lastNode = lastNode->next;
	/* Move the last node to the top of the stack */
	lastNode->next = *stack;
	lastNode->prev->next = NULL;
	lastNode->prev = NULL;
	(*stack)->prev = lastNode;
	(*stack) = lastNode;
	/* Adjust the stack pointer to point to the new top of the stack*/
	*stack = lastNode;
}
