#include "monty.h"

/**
 * sub - Subtract the top two elements of the stack.
 * @stack: Pointer to pointer to the stack.
 * @count_num: Line number in the Monty bytecode file.
 *
 * Description: This function subtracts the top element of the stack from the
 * second element and removes the first element. If the stack is too short or
 * empty, it prints an error message and exits.
 */
void sub(stack_t **stack, unsigned int count_num)
{
    stack_t *top_element;

    top_element = *stack;

    if (*stack != NULL && (*stack)->next != NULL)
    {
        *stack = top_element->next;
        (*stack)->prev = NULL;
        (*stack)->n -= top_element->n;
        free(top_element);
    }
    else
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", count_num);
        fclose(global_var.fd);
        free(global_var.buffer);
        free_list(stack);
        exit(EXIT_FAILURE);
    }
}
