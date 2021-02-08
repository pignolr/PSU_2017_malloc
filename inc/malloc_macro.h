/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** malloc_macro.h
*/

#ifndef MALLOC_MACRO_H_
	#define MALLOC_MACRO_H_

	#include <unistd.h>

	#define MEM_INIT sysconf(_SC_PAGESIZE)
	#define MEM_ADD sysconf(_SC_PAGESIZE)

#endif /* !MALLOC_MACRO_H_ */
