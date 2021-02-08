/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** free.c
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "malloc.h"
#include "malloc_private.h"
#include "malloc_macro.h"

static void	exit_free_corruption(void *ptr)
{
	char	buff[256];

	snprintf(buff, 256, "Error: double free or corruption: %p\n", ptr);
	write(2, buff, strlen(buff));
	exit(84);
}

void	malloc_list_destroy(void)
{
	malloc_list_t	*list;

	list = get_malloc_list();
	list->first = NULL;
	list->last = NULL;
	list->first_free = NULL;
	list->n = 0;
	brk(list->oldptr);
	list->oldptr = NULL;
	del_malloc_mutex();
}

void	do_free(void *ptr)
{
	malloc_list_t	*list;
	malloc_elem_t	*elem;

	list = get_malloc_list();
	elem = (malloc_elem_t *)ptr - 1;
	if (elem->free)
		exit_free_corruption(ptr);
	malloc_list_free_push(elem);
	elem->free = true;
	elem->size += elem->buff;
	elem->buff = 0;
	merge_elem(elem);
	if (list->n == 1 && list->first->free == true)
		malloc_list_destroy();
	else if (list->last->free == true
		&& list->last->size / MEM_ADD > 0)
		remove_page();
}

void	free(void *ptr)
{
	if (!ptr)
		return ;
	lock_malloc_mutex();
	do_free(ptr);
	unlock_malloc_mutex();
}
