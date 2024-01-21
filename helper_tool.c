#include "monty.h"

/**
 * callFunction - this will Calls the required function based
 * on the opcode and format.
 * @functionPtr: it Point to the function that is about to be called.
 * @opcode: thi is the String representing the opcode.
 * @value: this is the String representing a numeric value.
 * @lineNum: it is the Line number for the instruction.
 * @dataStructureFormat: Format specifier. If 0,
 * nodes will be entered as a stack.
 *If 1, nodes will be entered as a queue.
 */
void callFunction(op_func functionPtr, char *opcode,
char *value, int lineNum, int dataStructureFormat)
{
	stack_t *node;
	int flag;
	int i = 0;

	flag = 1;
	if (strcmp(opcode, "push") == 0)
	{
		if (value != NULL && value[0] == '-')
		{
			value = value + 1;
			flag = -1;
		}
		if (value == NULL)
			F_errorche(5, lineNum);
		while (value[i] != '\0')
		{
			if (!isdigit(value[i]))
				F_errorche(5, lineNum);
			i++;
		}
		node = createnode(atoi(value) * flag);
		if (dataStructureFormat == 0)
			functionPtr(&node, lineNum);
		else if (dataStructureFormat == 1)
			addtoqueue(&node, lineNum);
	}
	else
	{
		functionPtr(&head, lineNum);
	}
}

/**
 * findFunction - this will Finds the appropriate
 * function for the given opcode.
 * @opcode: this is The opcode.
 * @value: This is Argument of the opcode.
 * @lineNum: this is  Line number.
 * @format: Storage format. If 0, nodes will be entered as a stack.
 * If 1, nodes will be entered as a queue.
 * Return: return void
 */

void findFunction(char *opcode, char *value, int  lineNum, int format)
{
	int i = 0;
	int flag = 1;

	instruction_t func_list[] = {
		{"push", push_to_add},
		{"pall", print_stack_elements},
		{"pint", printTopNode},
		{"pop", poptop},
		{"nop", nop},
		{"swap", swap_element},
		{"add", addNodes},
		{"sub", sub_element},
		{"div", div_Nodes},
		{"mul", multiplyStackTop},
		{"mod", computeModulo},
		{"pchar", printAsciiValue},
		{"pstr", printString},
		{"rotl",  rotateFirstToBottom},
		{"rotr", rotateStackTop},
		{NULL, NULL}
	};
if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			callFunction(func_list[i].f, opcode, value, lineNum, format);
			flag = 0;
		}
	}
	if (flag == 1)
		F_errorche(3, lineNum, opcode);
}
