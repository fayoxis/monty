#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

void multiplyStackTop(stack_t **stack, unsigned int line_number);
void computeModulo(stack_t **stack, unsigned int line_number);
void print_stack_elements(stack_t **stack, unsigned int line_number);
void poptop(stack_t **stack, unsigned int line_number);
void printTopNode(stack_t **stack, unsigned int line_number);
void push_to_add(stack_t **, unsigned int);
void printAsciiValue(stack_t **stack, unsigned int line_number);
void printString(stack_t **, unsigned int);

void rotateFirstToBottom(stack_t **, unsigned int);
void rotateStackTop(stack_t **, unsigned int);
void openFile(char *fileName);
void r_File(FILE *f_Des);
int tokenizeLine(char *buffer, int line_number, int storageFormat);
void F_errorche(int error_code, ...);
void handleErrors(int errorCode, ...);
void handleStr_Errors(int errorCode, ...);
void addNodes(stack_t **stack, unsigned int line_number);
void div_Nodes(stack_t **stack, unsigned int line_number);
void sub_element(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void swap_element(stack_t **stack, unsigned int line_number);
void callFunction(op_func functionPtr, char *opcode,
char *value, int lineNum, int dataStructureFormat);
void findFunction(char *opcode, char *value, int  lineNum, int format);
stack_t *createnode(int n);
void free_nodes(void);
void addtoqueue(stack_t **, unsigned int);

#endif
