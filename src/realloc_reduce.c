/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** realloc.c
*/

#include "malloc_private.h"

void	malloc_list_pop(malloc_elem_t *elem)
{
	malloc_list_t	*list;

	list = get_malloc_list();
	if (list->last == elem)
		list->last = elem->prev;
	else
		elem->next->prev = elem->prev;
	if (elem->prev) {
		elem->prev->buff += elem->size + sizeof(malloc_elem_t);
		elem->prev->next = elem->next;
	}
	--list->n;
}

void	realloc_give_mem_to_next(malloc_elem_t *elem, size_t size)
{
	malloc_list_free_pop(elem->next);
	malloc_list_pop(elem->next);
	malloc_elem_split(elem, size);
}

malloc_elem_t	*realloc_reduce(malloc_elem_t *elem, size_t size)
{
	if (elem->next && elem->next->free)
		realloc_give_mem_to_next(elem, size);
	else if (elem->buff + elem->size - size >= sizeof(malloc_elem_t))
		malloc_elem_split(elem, size);
	else
		elem->buff += elem->size - size;
	elem->size = size;
	return (elem + 1);
}
