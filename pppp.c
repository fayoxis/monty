#include "monty.h"

/**
 * push_to_add - Adds a new node to the top of the stack.
 * @new_node: Pointer to the new node.
 * @line_number: The line number corresponding to the opcode.
 *
 * Description: This function adds a new node to the top of the stack.
 * If the stack is empty, the new node becomes the head of the stack.
 * Otherwise, the new node is inserted at the top of the stack and
 * the previous head is updated accordingly.
 */
void push_to_add(stack_t **new_node, __attribute__(
(unused))unsigned int line_number)
{
        stack_t *current;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	current = head;
	head = *new_node;
	head->next = current;
	current->prev = head;
}
/**
 * print_stack_elements - Prints the elements of a stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: The line number where the opcode is executed.
 *
 * Description: This function traverses the stack and prints the integer value
 * of each node in the stack, starting from the top. The line number
 * parameter is not used in this function, but it is included for
 * consistency with other functions in the program.
 */
void print_stack_elements(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * poptop - Removes the top node from the stack.
 * @stack: Double pointer to the top node of the stack.
 * @line_number: The line number corresponding to the opcode.
 *
 * Description: This function removes the top node from the stack
 * and updates the stack pointer accordingly. If the stack is empty,
 * it raises an error with the specified line number.
 */
void poptop(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (stack == NULL || *stack == NULL)
		handleErrors(7, line_number);

	while (*stack != NULL)
	{
		current = *stack;
		*stack = current->next;
		if (*stack != NULL)
			(*stack)->prev = NULL;
		free(current);
	}
}
/**
 * printTopNode - Prints the value of the top node in the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 *
 * This function prints the value of the top node in the stack.
 * If the stack is empty or uninitialized, it raises an error.
 */
void printTopNode(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		handleErrors(6, line_number);
	printf("%d\n", (*stack)->n);
}
