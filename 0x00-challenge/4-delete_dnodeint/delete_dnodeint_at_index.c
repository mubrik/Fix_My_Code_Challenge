#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *tmp = NULL, *prev = NULL, *next = NULL;
	int status = -1;
	unsigned int i = 0;

	if (!head)
		return (status);
	/* make sure start of node */
	tmp = *head;
	while (tmp)
	{
		if (!tmp->prev)
			break;
		tmp = tmp->prev;
	}
	/* iterate */
	while (tmp)
	{
		if (index == i)
		{
			/* extract necessary ptr */
			prev = tmp->prev;
			next = tmp->next;
			/* if prev null starting index == 0, make next item start of list/null */
			if (!prev)
				*head = next;
			else
				prev->next = next;
			/* if next null, last item in list */
			if (next)
				next->prev = prev;
			free(tmp), status = 1;
			break;
		}
		tmp = tmp->next, i++;
	}

	return (status);
}
