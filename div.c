#include "monty.h"

/**
 * div - Divide the second top element of the stack by the top element.
 * @stack: Pointer to pointer to the stack.
 * @count_num: Line number in the file.
 */
void div(stack_t **stack, unsigned int count_num)
{
    stack_t *top_element;
    int divisor, dividend;

    top_element = *stack;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't div, stack too short\n", count_num);
        fclose(global_var.fd);
        free(global_var.buffer);
        free_list(stack);
        exit(EXIT_FAILURE);
    }

    divisor = top_element->n;

    if (divisor == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", count_num);
        fclose(global_var.fd);
        free(global_var.buffer);
        free_stack(stack);
        exit(EXIT_FAILURE);
    }

    *stack = top_element->next;
    (*stack)->prev = NULL;

    dividend = (*stack)->n;
    (*stack)->n = dividend / divisor;

    free(top_element);
}
