#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list.
 * @head: pointer to the beginning of the list
 *
 * Return: address of the node where the loop starts or NULL if there's no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tortoise, *ma;

	tortoise = ma = head;
	while (tortoise && ma && ma->next)
	{
		tortoise = tortoise->next;
		ma = ma->next->next;
		if (tortoise == ma)
		{
			tortoise = head;
			break;
		}
	}
	if (!tortoise || !ma || !ma->next)
		return (NULL);
	while (tortoise != ma)
	{
		tortoise = tortoise->next;
		ma = ma->next;
	}
	return (ma);
}
