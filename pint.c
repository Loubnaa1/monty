#include "monty.h"
/**
 * pint - function that prints the value at the top of the stack
 * @stack: pointer to pointer to structure
 * @count_num: lines number of the file
 * Return: nothing
 */
void pint(stack_t **stack, unsigned int count_num)
{
	if (*stack != NULL)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", count_num);
		fclose(global_var.fd);
		free(global_var.buffer);
		free_list(stack);
		exit(EXIT_FAILURE);
	}
}
