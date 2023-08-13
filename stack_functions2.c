#include "monty.h"

/**
 * pall - Prints top of stack to bottom
 *
 * @stack: Location to the start of the stack
 * @lineNum: line number in input file
 */
void pall(stack_t **stack, unsigned int lineNum)
{
	stack_t *temp;

	(void)lineNum;

	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - prints integer at the top of the stack
 *
 * @stack: Location to the start of the stack
 * @lineNum: line number in input file
 */
void pint(stack_t **stack, unsigned int lineNum)
{
	(void) lineNum;
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", lineNum);
		free_stack(&head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}


/**
 * nop - Literally does nothing
 *
 * @stack: Location to the start of the stack
 * @lineNum: line number in input file
 */
void nop(stack_t **stack, unsigned int lineNum)
{
	(void)stack;
	(void)lineNum;
}
