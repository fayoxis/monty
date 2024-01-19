#include "monty.h"

/**
 * multiplyStackTop - Multiplies the top two elements of the stack.
 * @stack: Pointer to the top node of the stack.
 * @line_number: The line number where the multiplication operation occurs.
 */
void multiplyStackTop(stack_t **stack, unsigned int line_number)
{
	int product;

	while (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		handleErrors(8, line_number, "mul");
	(*stack) = (*stack)->next;
	product = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = product;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * computeModulo - Computes the modulo operation on the top
 * two elements of the stack.
 * @stack: it is a Pointer to a pointer pointing to the top
 * node of the stack.
 * @line_number: this is An unsigned integer representing
 * the line number of the opcode.
 */
void computeModulo(stack_t **stack, unsigned int line_number)
{
	int product;

	while (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		handleErrors(8, line_number, "mod");
	while ((*stack)->n == 0)
		handleErrors(9, line_number);
	(*stack) = (*stack)->next;
	product = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = product;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * div_Nodes - Divides the top two elements of the stack.
 * @stack: this will Point to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void div_Nodes(stack_t **stack, unsigned int line_number)
{
	int product;

	while (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		handleErrors(8, line_number, "div");
	while ((*stack)->n == 0)
		handleErrors(9, line_number);
	(*stack) = (*stack)->next;
	product = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = product;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
