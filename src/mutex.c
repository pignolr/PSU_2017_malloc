/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** mutex.c
*/

#include <pthread.h>
#include "malloc_list.h"

void	del_malloc_mutex(void)
{
	malloc_list_t	*list;

	list = get_malloc_list();
	pthread_mutex_destroy(&list->lock);
}

void	lock_malloc_mutex(void)
{
	malloc_list_t	*list;

	list = get_malloc_list();
	pthread_mutex_lock(&list->lock);
}

void	unlock_malloc_mutex(void)
{
	malloc_list_t	*list;

	list = get_malloc_list();
	pthread_mutex_unlock(&list->lock);
}
