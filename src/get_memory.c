/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** malloc_list.c
*/

#include "malloc_private.h"

malloc_elem_t	*get_min_memory(size_t size)
{
	malloc_list_t	*list;
	malloc_elem_t	*lower;
	malloc_elem_t	*it;

	list = get_malloc_list();
	it = list->first_free;
	lower = NULL;
	while (it) {
		if (it->size >= size
			&& (!lower || lower->size > it->size
			|| (lower->size == it->size && lower > it)))
			lower = it;
		it = it->next_free;
	}
	return (lower);
}

malloc_elem_t	*get_memory(size_t size)
{
	malloc_elem_t	*elem;

	elem = get_min_memory(size);
	if (elem)
		return (elem);
	elem = add_page(size);
	if (elem)
		return (elem);
	return (NULL);
}
