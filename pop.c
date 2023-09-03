#include "monty.h"

/**
 * pop - Removes the top element of the stack.
 * @stack: Pointer to pointer to the stack.
 * @count_num: Line number in the Monty bytecode file.
 *
 * Description: This function removes the top element of the stack.
 * If the stack is empty, it prints an error message and exits.
 */
void pop(stack_t **stack, unsigned int count_num)
{
    stack_t *top_element;

    if (*stack != NULL)
    {
        top_element = *stack;
        
        if ((*stack)->next != NULL)
        {
            *stack = top_element->next;
            (*stack)->prev = NULL;
        }
        else
        {
            *stack = NULL;
        }

        free(top_element);
    }
    else
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", count_num);
        fclose(global_var.fd);
        free(global_var.buffer);
        free_list(stack);
        exit(EXIT_FAILURE);
    }
}
