#include "monty.h"

/**
 * createnode - this will actually Creates a node.
 * @n: this is the Number to go inside the node.
 * Return: return Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *createnode(int n)
{
	stack_t *node;

	while (1)
	{
		node = malloc(sizeof(stack_t));
		if (node == NULL)
		{
			/* Handle error */
			handleErrors(4);
		}
		else
		{
			break;
			/* Exit the loop if memory allocation is successful */
		}
	}
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * free_nodes - this is the Frees nodes in the stack.
 */
void free_nodes(void)
{
	stack_t *current;

	if (head == NULL)
		return;
	while (head != NULL)
	{
		current = head;
		head = head->next;
		free(current);
	}
}

/**
 * addtoqueue - this will Add a node to the queue.
 * @new_node: it Pointe to the new node.
 * @lineNum: line number of the opcode.
 */
void addtoqueue(stack_t **new_node, __attribute__((unused))
unsigned int lineNum)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;

	if (tmp->next != NULL)
	{
	do {
		tmp = tmp->next;
	} while (tmp->next != NULL);
	}
	tmp->next = *new_node;
	(*new_node)->prev = tmp;
}
