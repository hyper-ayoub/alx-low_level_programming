#include "lists.h"

/**
 * get_dnodeint_at_index - return the nth of a dlistint_t list
 * @head: pointer to the head of list
 * @index: index of node
 *
 * Return: note at index index or NULL.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistsint *temp;

	temp = head;
	while (index != 0 && temp != NULL)
	{
		temp = temp->next;
		index--;
	}
	return (temp);
}
