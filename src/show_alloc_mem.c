/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** show_alloc_mem.c
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "malloc_private.h"

static void	show_break(void)
{
	char	buff[256];

	memset(buff, 0, 256);
	snprintf(buff, 256, "break" " : %p\n", sbrk(0));
	write(1, buff, strlen(buff));
}

static void	show_memory_block(const malloc_elem_t *elem)
{
	char	buff[256];

	memset(buff, 0, 256);
	snprintf(buff, 256, "%p - %p : %lu bytes\n",
		elem + 1,
		(void *)((size_t)(elem + 1) + elem->size),
		elem->size);
	write(1, buff, strlen(buff));
}

static void	show_memories_blocks(void)
{
	malloc_list_t	*list;
	malloc_elem_t	*elem;

	list = get_malloc_list();
	elem = list->first;
	while (elem) {
		if (elem->free == false)
			show_memory_block(elem);
		elem = elem->next;
	}
}

void	show_alloc_mem(void)
{
	show_break();
	show_memories_blocks();
}
