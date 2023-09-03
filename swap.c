#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Pointer to pointer to the stack.
 * @count_num: Line number in the Monty bytecode file.
 *
 * Description: This function swaps the positions of the top two elements on
 * the stack. If the stack is too short or empty, it prints an error message
 * and exits.
 */
void swap(stack_t **stack, unsigned int count_num)
{
    stack_t *temp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", count_num);
        fclose(global_var.fd);
        free(global_var.buffer);
        free_list(stack);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    *stack = temp->next;
    (*stack)->prev = NULL;
    temp->next = (*stack)->next;
    (*stack)->next = temp;
    temp->prev = *stack;
}
