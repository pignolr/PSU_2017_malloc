/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** realloc.c
*/

#include <unistd.h>
#include <string.h>
#include "malloc.h"
#include "malloc_private.h"

void	realloc_get_mem_from_next(malloc_elem_t *elem, size_t size)
{
	size_t	diff;

	diff = size - elem->size;
	malloc_list_free_pop(elem->next);
	malloc_list_pop(elem->next);
	elem->size = size;
	elem->buff -= diff;
	if (elem->buff >= sizeof(malloc_elem_t))
		malloc_elem_split(elem, size);
}

malloc_elem_t	*realloc_in_other_elem(malloc_elem_t *elem, size_t size)
{
	malloc_elem_t	*old_elem;

	old_elem = elem;
	elem = do_malloc(size);
	if (!elem)
		return (NULL);
	--elem;
	memcpy(elem + 1, old_elem + 1, old_elem->size);
	do_free(old_elem + 1);
	return (elem);
}

malloc_elem_t	*realloc_increase(malloc_elem_t *elem, size_t size)
{
	size_t	diff;

	diff = size - elem->size;
	if (elem->buff >= diff) {
		elem->size = size;
		elem->buff -= diff;
	} else if (elem->next && elem->next->free
		&& elem->next->size + sizeof(malloc_elem_t) >= diff)
		realloc_get_mem_from_next(elem, size);
	else
		elem = realloc_in_other_elem(elem, size);
	return (elem + 1);
}
