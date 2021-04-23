SRC = *.c 

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

OBJS = ${SRC:.c=.o}

.c.o:
	gcc ${CFLAGS} -I ./includes -c $< -o ${SRC:.c=.o}
	
all: ${NAME}

clean: 
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

libft.a: ${OBJS}
	ar rc ${NAME} ${OBJS}

%.o: 
	gcc ${CFLAGS} -I ./includes -c $^ -o $@

.PHONY: libft.a all clean fclean re



