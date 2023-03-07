NAME = push_swap

SRC = push_swap.c \
		lst.c \
		lst_2.c	\
		instru.c \
		create_stack.c	\
		move_to_b.c	\
		sort.c \
		sort_small.c 

OBJ = ${patsubst %.c, %.o, ${SRC}}

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

all : ${NAME}

${NAME}:
	make -C myprintf && mv myprintf/libftprintf.a .
	make -C libft && mv libft/libft.a .
	${CC} ${CFLAGS} ${SRC} -o ${NAME} libft.a libftprintf.a

%.o : %.c
	${CC} ${CFLAGS} -o $@ -c $<

clean :
	rm -f ${OBJ}
	make -C myprintf clean
	make -C libft clean

fclean : clean
		rm -f ${NAME} *.a
		make -C myprintf fclean
		make -C libft fclean

re : fclean all

.PHONY: re fclean clean all
