#include "monty.h"

/**
 * add - Add the top two elements of the stack and remove the first one.
 * @stack: Pointer to pointer to the stack.
 * @count_num: Line number in the file.
 */
void add(stack_t **stack, unsigned int count_num)
{
    stack_t *top_element;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        fclose(global_var.fd);
        free(global_var.buffer);
        free_stack(stack);
        exit(EXIT_FAILURE);
    }

    top_element = *stack;
    *stack = top_element->next;
    (*stack)->prev = NULL;

    (*stack)->n += top_element->n;

    free(top_element);
}
