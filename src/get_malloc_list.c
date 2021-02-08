/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** malloc.c
*/

#include <pthread.h>
#include <unistd.h>
#include "malloc_private.h"
#include "malloc_macro.h"

static int	create_first_page(void)
{
	malloc_list_t	*list;

	list = get_malloc_list();
	list->oldptr = sbrk(MEM_INIT);
	if (list->oldptr == (void *)-1)
		return (1);
	return (0);
}

int	malloc_list_init(void)
{
	malloc_list_t	*list;

	list = get_malloc_list();
	if (create_first_page() || pthread_mutex_init(&list->lock, NULL))
		return (1);
	list->n = 1;
	list->first = (malloc_elem_t *)list->oldptr;
	list->first_free = (malloc_elem_t *)list->oldptr;
	list->first->next = NULL;
	list->first->prev = NULL;
	list->first->next_free = NULL;
	list->first->prev_free = NULL;
	list->first->size = MEM_INIT - sizeof(malloc_elem_t);
	list->first->buff = 0;
	list->first->free = true;
	list->last = list->first;
	return (0);
}

malloc_list_t	*get_malloc_list(void)
{
	static malloc_list_t	list = {
		NULL, NULL, NULL,
		0,
		NULL,
		PTHREAD_MUTEX_INITIALIZER
	};

	return (&list);
}
