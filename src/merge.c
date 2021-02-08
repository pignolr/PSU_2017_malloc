/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** merge.c
*/

#include "malloc_private.h"

void	merge_with_next(malloc_elem_t *elem)
{
	malloc_list_t *list;

	list = get_malloc_list();
	elem->size += sizeof(malloc_elem_t) + elem->next->size;
	malloc_list_free_pop(elem->next);
	if (elem->next == list->last)
		list->last = elem;
	else
		elem->next->next->prev = elem;
	elem->next = elem->next->next;
	list->n -= 1;
}

void	merge_elem(malloc_elem_t *elem)
{
	if (elem->next && elem->next->free)
		merge_with_next(elem);
	if (elem->prev && elem->prev->free)
		merge_with_next(elem->prev);
}
