#include "monty.h"

/**
 * _add - function that adds the top two elements of the stack.
 * @stack: double pointer to the head of stack.
 * @line_number: script line number.
 *
 * Usage: add .
 * If the stack contains less than two elements, print the error message,
 * L<line_number>: can't swap, stack too short, followed by a new line,
 * and exit with the status EXIT_FAILURE .
 * The result is stored in the second top element of the stack, and the,
 * top element is removed, so that at the end:
 * The top element of the stack contains the result and the stack is one,
 * element shorter
 *
 * Return: No return.
 */
void _add(stack_t **stack, unsigned int line_number)
{
	int temp_variable;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp_variable = (*stack)->n;
	_pop(stack, line_number);
	(*stack)->n += temp_variable;
}

#include "monty.h"

/**
 * _pchar - function that prints the char at the top of the stack.
 * @stack: double pointer to the head of stack
 * @line_number: script line number.
 *
 * The integer stored at the top of the stack is treated as the ascii,
 * value of the character to be printed.
 * If the value is not in the ascii table (man ascii) print the error,
 * message L<line_number>: can't pchar, value out of range, followed by,
 * a new line, and exit with the status EXIT_FAILURE.
 * If the stack is empty, print the error message:
 * L<line_number>: can't pchar, stack empty, followed by a new line, and,
 * exit with the status EXIT_FAILURE .
 *
 * Return: No return.
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	int ch;

	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	ch = (*stack)->n;
	if (!isascii(ch))
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", ch);
}

#include "monty.h"

/**
 * _pstr - function that prints the string starting at top of the stack.
 * @stack: double pointer to the head of stack
 * @line_number: script line number.
 *
 * The integer stored at the top of the stack is treated as the ascii,
 * value of the character to be printed.
 * The string stops when either: the stack is over, the value of the,
 * element is 0 or the value of the element is not in the ascii table.
 * If the stack is empty, print only a new line.
 *
 * Return: No return.
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_variable = *stack;

	(void)(line_number);
	if (!(*stack))
	{
		printf("\n");
		return;
	}
	while (temp_variable)
	{
		if (isascii(temp_variable->n) && temp_variable->n != 0)
			putchar(temp_variable->n);
		else
			break;
		temp_variable = temp_variable->next;
	}
	putchar('\n');
}

#include "monty.h"

/**
 * _rotl - function that rotates the stack to the top.
 * @stack: double pointer to the head of stack
 * @line_number: script line number.
 *
 * The top element of the stack becomes the last one, and the second top,
 * element of the stack becomes the first one.
 * rotl never fails.
 *
 * Return: No return.
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_variable = *stack, *new_top;

	(void)(line_number);
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	new_top = (*stack)->next;
	new_top->prev = NULL;
	while (temp_variable->next != NULL)
		temp_variable = temp_variable->next;
	temp_variable->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = temp_variable;
	(*stack) = new_top;
}
