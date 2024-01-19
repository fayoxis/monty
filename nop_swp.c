#include "monty.h"

/**
 * nop - this actually Does nothing.
 * @stack: this will point to a pointer pointing to top
 * node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * swap_element - Swaps the positions of the top
 * two elements in the stack
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: The line number representing the opcode.
 *
 * Description: This function swaps the positions of the top
 * two elements of the stack
 * If there are less than two elements in the stack,
 * an error message is displayed
 */
void swap_element(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	while (stack != NULL && *stack != NULL && (*stack)->next != NULL)
	{
		tmp = (*stack)->next;
		(*stack)->next = tmp->next;

		if (tmp->next != NULL)
			tmp->next->prev = *stack;

		tmp->next = *stack;
		(*stack)->prev = tmp;
		tmp->prev = NULL;

		*stack = tmp;
		return; /* Exit the loop after one iteration */
	}
	/* Error message if there are less than two elements in the stack */
	handleErrors(8, line_number, "swap");
}
