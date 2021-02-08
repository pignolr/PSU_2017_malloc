/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** calloc.c
*/

#include <string.h>
#include "malloc_private.h"

void	*do_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = do_malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	return (memset(ptr, 0, nmemb * size));
}

void	*calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	lock_malloc_mutex();
	ptr = do_calloc(nmemb, size);
	unlock_malloc_mutex();
	return (ptr);
}
