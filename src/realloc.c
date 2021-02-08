/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** realloc.c
*/

#include "malloc_private.h"

void	*do_realloc(void *ptr, size_t size)
{
	malloc_elem_t	*elem;

	elem = (malloc_elem_t *)ptr;
	--elem;
	if (elem->size == size)
		return (ptr);
	else if (elem->size > size)
		return (realloc_reduce(elem, size));
	else
		return (realloc_increase(elem, size));
}

void	*realloc(void *ptr, size_t size)
{
	lock_malloc_mutex();
	if (!ptr)
		ptr = do_malloc(size);
	else if (!size) {
		do_free(ptr);
		ptr = NULL;
	} else
		ptr = do_realloc(ptr, size);
	unlock_malloc_mutex();
	return (ptr);
}
