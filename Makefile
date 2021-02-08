##
## EPITECH PROJECT, 2018
## Malloc
## File description:
## Makefile
##

CC		=	gcc

CFLAGS		+=	-W -Wall -Wextra -Werror

DEBUG		?=	0
ifeq ($(DEBUG), 1)
	CFLAGS +=	-g
endif

CPPFLAGS	+=	-Iinc -fpic

LDFLAGS		+=	-shared

LDLIBS		+=

NAME		=	libmy_malloc.so

SRCS		=	src/get_malloc_list.c \
			src/mutex.c \
			src/get_memory.c \
			src/malloc.c \
			src/malloc_list.c \
			src/memory_page.c \
			src/malloc_list_free.c \
			src/free.c \
			src/merge.c \
			src/realloc.c \
			src/realloc_reduce.c \
			src/realloc_increase.c \
			src/calloc.c \
			src/show_alloc_mem.c

OBJS		=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
