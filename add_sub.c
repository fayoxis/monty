#include "monty.h"

/**
 * addNodes - this will add the top two elements of the stack.
 * @stack: this will point a Pointer to a pointer pointing to
 * the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void addNodes(stack_t **stack, unsigned int line_number)

{
	int product;

	while (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		handleErrors(8, line_number, "add");

	(*stack) = (*stack)->next;
	product = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = product;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * sub_element - this will Adds the top two elements of the stack.
 * @stack: this will Point to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void sub_element(stack_t **stack, unsigned int line_number)
{
	int product;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		handleErrors(8, line_number, "sub");
	(*stack) = (*stack)->next;
	product = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = product;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
