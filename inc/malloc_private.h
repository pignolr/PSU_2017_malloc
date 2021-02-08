/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** malloc_private.h
*/

#ifndef MALLOC_PRIVATE_H_
	#define MALLOC_PRIVATE_H_

	#include "malloc_list.h"

malloc_elem_t	*get_memory(size_t);

int		malloc_list_init(void);
malloc_elem_t	*malloc_list_add(size_t);
void		malloc_elem_split(malloc_elem_t *, size_t);

void		malloc_list_pop(malloc_elem_t *elem);
void		malloc_list_free_push(malloc_elem_t *);
void		malloc_list_free_pop(malloc_elem_t *);

malloc_elem_t	*add_page(size_t);
void		remove_page(void);

void		merge_elem(malloc_elem_t *);

void		*do_malloc(size_t);
void		do_free(void *);

malloc_elem_t	*realloc_reduce(malloc_elem_t *, size_t);
malloc_elem_t	*realloc_increase(malloc_elem_t *, size_t);

void		lock_malloc_mutex(void);
void		unlock_malloc_mutex(void);
void		del_malloc_mutex(void);

#endif /* !MALLOC_PRIVATE_H_ */
