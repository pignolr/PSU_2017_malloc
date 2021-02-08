/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** malloc_list_free.c
*/

#include "malloc_list.h"

void	malloc_list_free_push(malloc_elem_t *elem)
{
	malloc_list_t *list;

	list = get_malloc_list();
	elem->next_free = list->first_free;
	if (elem->next_free)
		elem->next_free->prev_free = elem;
	elem->prev_free = NULL;
	list->first_free = elem;
}

void	malloc_list_free_pop(malloc_elem_t *elem)
{
	malloc_list_t *list;

	list = get_malloc_list();
	if (elem->next_free)
		elem->next_free->prev_free = elem->prev_free;
	if (list->first_free == elem)
		list->first_free = elem->next_free;
	else
		elem->prev_free->next_free = elem->next_free;
	elem->prev_free = NULL;
	elem->next_free = NULL;
}
