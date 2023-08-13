#include "monty.h"

stack_t *head = NULL;
/**
 * main - This function takes input to call functions on stack
 *
 * @argc: Count of arguments given in call of function
 * @argv: Array of arguments given in call of function
 *
 * Return: Returns 0 on success
 */
int main(int argc, char **argv)
{
		if (argc != 2)
		{
			fprintf(stderr, "USAGE: monty file\n");
			free_stack(&head);
			exit(EXIT_FAILURE);
		}
		open_file(argv[1]);
		free_stack(&head);
		return (0);
}

/**
 * addNewNode - creates a new node with a value of n
 *
 * @n: Number stored inside of new node
 *
 * Return: Returns pointer to new node if successful, else NULL
 */

stack_t *addNewNode(int num)
{
	stack_t *stack;

	stack = malloc(sizeof(stack_t));
	if (stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(&head);
		exit(EXIT_FAILURE);
	}
	stack->next = NULL;
	stack->prev = NULL;
	stack->n = num;
	return (stack);
}

/**
 * free_stack - frees each node in the stack
 *
 * @stack: stack of node
 */
void free_stack(stack_t **stack)
{
	if (stack == NULL || *stack == NULL)
		return;

	free_stack(&((*stack)->next));
	free(*stack);
	*stack = NULL;
}
