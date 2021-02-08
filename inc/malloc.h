/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** malloc.h
*/

#ifndef MALLOC_H_
	#define MALLOC_H_

	#include <stdlib.h>

void	show_alloc_mem(void);
void	*malloc(size_t);
void	*realloc(void *, size_t);
void	free(void *);
void	*calloc(size_t, size_t);

#endif /* !MALLOC_H_ */
