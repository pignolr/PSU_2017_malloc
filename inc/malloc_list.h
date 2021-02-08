/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** malloc_list.h
*/

#ifndef LIST_MALLOC_H_
	#define LIST_MALLOC_H_

	#include <stdlib.h>
	#include <stdbool.h>

typedef struct			malloc_elem {
	size_t			size;
	size_t			buff;
	bool			free;
	struct malloc_elem	*next;
	struct malloc_elem	*prev;
	struct malloc_elem	*next_free;
	struct malloc_elem	*prev_free;
}				malloc_elem_t;

typedef struct		s_malloc_list {
	malloc_elem_t	*first;
	malloc_elem_t	*last;
	malloc_elem_t	*first_free;
	size_t		n;
	void		*oldptr;
	pthread_mutex_t	lock;
}			malloc_list_t;

malloc_list_t	*get_malloc_list();

#endif /* !LIST_MALLOC_H_ */
