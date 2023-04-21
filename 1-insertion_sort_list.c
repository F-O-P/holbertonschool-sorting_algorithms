#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending order
 * @list: a list of integers
 * Return: a pointer to the sorted list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next, *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = *list;
	while (current != NULL)
	{
		next = current->next;
		while (current->prev != NULL && current->n < current->prev->n)
		{
			prev = current->prev;
			prev->next = current->next;
			if (current->next != NULL)
				current->next->prev = prev;
			current->next = prev;
			current->prev = prev->prev;
			prev->prev = current;
			if (current->prev == NULL)
				*list = current;
			else
				current->prev->next = current;
			print_list(*list);
		}
		current = next;
	}
}
