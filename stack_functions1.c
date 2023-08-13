#include "monty.h"

/**
 * push - add an element to the stack
 *
 * @newNode: pointer to the node new node
 * @lineNum: line number in input file
 */
void push(stack_t **newNode, __attribute__((unused))unsigned int lineNum)
{
	stack_t *temp;

	if (newNode == NULL || *newNode == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *newNode;
		return;
	}
	temp = head;
	head = *newNode;
	head->next = temp;
	temp->prev = head;
}

/**
 * pop - Removes a node from the top of the stack
 *
 * @stack: Location to the start of the stack
 * @lineNum: line number in input file
 */
void pop(stack_t **stack, unsigned int lineNum)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", lineNum);
		free_stack(&head);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}


/**
 * swap - swaps two nodes on the top of the stack
 *
 * @stack: Location to the start of the stack
 * @lineNum: line number in input file
 */
void swap(stack_t **stack, unsigned int lineNum)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", lineNum);
		free_stack(&head);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}


/**
 * add - adds top two nodes together
 *
 * @stack: Location to the start of the stack
 * @lineNum: line number in input file
 */
void add(stack_t **stack, unsigned int lineNum)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", lineNum);
		free_stack(&head);
		exit(EXIT_FAILURE);
	}

	(*stack) = (*stack)->next;
	sum = (*stack)->prev->n + (*stack)->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
