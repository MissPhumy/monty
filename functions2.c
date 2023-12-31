#include "monty.h"

/**
 * _pint - function that prints the value at the top of the stack.
 * @stack: double pointer to the head of stack.
 * @line_number: script line number.
 *
 * Usage: pint .
 * If the stack is empty, print the error message,
 * L<line_number>: can't pint, stack empty, followed by a new line,
 * and exit with the status EXIT_FAILURE.
 *
 * Return: No return.
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

#include "monty.h"

/**
 * _pop - function that removes the top element of the stack.
 * @stack: double pointer to the head of stack
 * @line_number: script line number.
 *
 * If the stack is empty, print the error message,
 * L<line_number>: can't pop an empty stack, followed by a new line,
 * and exit with the status EXIT_FAILURE .
 *
 * Return: No return.
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *popped;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	popped  = *stack;
	(*stack) = (*stack)->next;
	free(popped);
}

#include "monty.h"

/**
 * _rotr - function that rotates the stack to the bottom.
 * @stack: double pointer to the head of stack
 * @line_number: script line number.
 *
 * The last element of the stack becomes the first one.
 * rotl never fails.
 *
 * Return: No return.
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_variable = *stack;

	(void)(line_number);
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	while (temp_variable->next != NULL)
		temp_variable = temp_variable->next;
	temp_variable->next = *stack;
	temp_variable->prev->next = NULL;
	temp_variable->prev = NULL;
	(*stack)->prev = temp_variable;
	(*stack) = temp_variable;
}

#include "monty.h"

/**
 * _swap - function that swaps the top two elements of the stack.
 * @stack: double pointer to the head of stack.
 * @line_number: script line number.
 *
 * Usage: swap .
 * If the stack contains less than two elements, print the error message,
 * L<line_number>: can't swap, stack too short, followed by a new line,
 * and exit with the status EXIT_FAILURE .
 *
 * Return: No return.
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_variable;

	(void)(line_number);
	if (!(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp_variable = (*stack)->next;
	(*stack)->prev = (*stack)->next;
	(*stack)->next = temp_variable->next;
	temp_variable->prev = NULL;
	(*stack)->prev = temp_variable;
	if (temp_variable->next)
		temp_variable->next->prev = *stack;
	temp_variable->next = *stack;
	(*stack) = (*stack)->prev;
}
