#include "monty.h"

/**
 * pall_s - Prints all the values on the stack, starting from the top.
 * @stack: Pointer to pointer to the stack.
 * @count_num: Line number file.
 *
 * Description: This function prints all the values on the stack, starting from
 * the top of the stack. It also handles an empty stack by printing a message.
 */
void pall_s(stack_t **stack, unsigned int count_num)
{
    stack_t *current;

    current = *stack;
    (void)(count_num); // Unused parameter, silence compiler warning.

    if (*stack != NULL)
    {
        for (; current != NULL; current = current->next)
        {
            printf("%d\n", current->n);
        }
    }
    else
    {
        printf("Stack is empty\n");
    }
}
