/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** malloc_list.c
*/

#include <unistd.h>
#include "malloc_private.h"
#include "malloc_macro.h"

void	malloc_elem_split_init(malloc_elem_t *new_elem,
			malloc_elem_t *elem,
			size_t size)
{
	new_elem->prev = elem;
	new_elem->next = elem->next;
	new_elem->free = true;
	new_elem->size = elem->size + elem->buff
		- (size + sizeof(malloc_elem_t));
	new_elem->buff = 0;
	elem->buff = 0;
}

void	malloc_list_push(malloc_elem_t *new_elem, malloc_elem_t *elem)
{
	malloc_list_t	*list;

	list = get_malloc_list();
	if (list->last == elem)
		list->last = new_elem;
	else
		elem->next->prev = new_elem;
	elem->next = new_elem;
	++list->n;
}

void	malloc_elem_split(malloc_elem_t *elem, size_t size)
{
	malloc_elem_t	*new_elem;

	new_elem = (malloc_elem_t *)
		((size_t)elem + sizeof(malloc_elem_t) + size);
	malloc_elem_split_init(new_elem, elem, size);
	malloc_list_free_push(new_elem);
	malloc_list_push(new_elem, elem);
}

malloc_elem_t	*malloc_list_add(size_t size)
{
	malloc_elem_t	*elem;

	elem = get_memory(size);
	if (!elem)
		return (NULL);
	if (elem->size - size > sizeof(malloc_elem_t))
		malloc_elem_split(elem, size);
	else
		elem->buff += elem->size - size;
	elem->size = size;
	elem->free = false;
	malloc_list_free_pop(elem);
	return (elem + 1);
}
