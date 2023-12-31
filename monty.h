#ifndef main_h
#define main_h

/* C Libraries*/
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <stdarg.h>
#include <ctype.h>

/* Data Structure */

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

/* External Variable */
extern stack_t *head;

typedef void (*instruction)(stack_t **stack, unsigned int line_number);

/* Function Prototypes */
void open_file(char *filename);
void read_file(FILE *fileReader);
int tokenize_line(char *line, int lineNum);
void match_function(char *func, char *numValue, int lineNum);
void execute_func(instruction f, char *func, char *numValue, int lineNum);
stack_t *addNewNode(int num);
void free_stack(stack_t **stack);

/*Stack Functions*/
void push(stack_t **newNode,  unsigned int lineNum);
void pop(stack_t **stack, unsigned int lineNum);
void swap(stack_t **stack, unsigned int lineNum);
void add(stack_t **stack, unsigned int lineNum);
void pall(stack_t **stack, unsigned int lineNum);
void pint(stack_t **stack, unsigned int lineNum);
void nop(stack_t **stack, unsigned int lineNum);

#endif
