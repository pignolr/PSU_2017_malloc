/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** memory_page.c
*/

#include <unistd.h>
#include "malloc_private.h"
#include "malloc_macro.h"

void	malloc_list_push_page(size_t mem_add)
{
	malloc_list_t	*list;
	malloc_elem_t	*new_elem;

	list = get_malloc_list();
	new_elem = (malloc_elem_t *)
		((size_t)list->last + sizeof(malloc_elem_t) + list->last->size);
	new_elem->free = true;
	new_elem->size = mem_add + list->last->buff - sizeof(malloc_elem_t);
	list->last->buff = 0;
	new_elem->buff = 0;
	new_elem->prev = list->last;
	list->last->next = new_elem;
	list->last = new_elem;
	malloc_list_free_push(new_elem);
	new_elem->next = NULL;
	++list->n;
}

malloc_elem_t	*add_page(size_t size)
{
	malloc_list_t	*list;
	size_t		mem_add;

	list = get_malloc_list();
	if (list->last->free == false)
		size += sizeof(malloc_elem_t);
	mem_add = ((size - 1) / MEM_ADD + 1) * MEM_ADD;
	if (sbrk(mem_add) == (void *)-1)
		return (NULL);
	if (list->last->free == true)
		list->last->size += mem_add;
	else
		malloc_list_push_page(mem_add);
	return (list->last);
}

void	remove_page(void)
{
	malloc_list_t	*list;
	size_t		size_p;

	list = get_malloc_list();
	size_p = (list->last->size / MEM_ADD) * MEM_ADD;
	list->last->size -= size_p;
	sbrk(-size_p);
}
