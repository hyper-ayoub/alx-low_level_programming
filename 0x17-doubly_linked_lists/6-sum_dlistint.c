#include "lists.h"

/**
 *  sum_dlistint - function that return the sum of all data
 *  @head: pointer to head to the list
 *
 *  Return: the sum of all the data (n) of a dlistint_t
 */
int sum_dlistint(dlistint_t *head)
{
	dlistint_t *temp;

	temp = head;
	while (index != 0 && temp != NULL)
	{
		temp = temp->next;
		index--;
	}
	return (temp);
}
