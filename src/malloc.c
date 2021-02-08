/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** malloc.c
*/

#include "malloc_private.h"

void	*do_malloc(size_t size)
{
	malloc_list_t	*list;

	list = get_malloc_list();
	if (!size || (!list->n && malloc_list_init()))
		return (NULL);
	return (malloc_list_add(size));
}

void	*malloc(size_t size)
{
	void	*ptr;

	lock_malloc_mutex();
	ptr = do_malloc(size);
	unlock_malloc_mutex();
	return (ptr);
}
