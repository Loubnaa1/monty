#include "monty.h"
/**
 * free_stack - Frees a struct list.
 * @stack: Pointer to structure pointer.
 * Return: Nothing.
 */
void free_stack(stack_t **stack)
{
    stack_t *head, *next;

    for (head = *stack; head != NULL; head = next)
    {
        next = head->next;
        free(head);
    }

    *stack = NULL;
}
