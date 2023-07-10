NAME = fdf
SRCS = main.c read_map.c draw_map.c draw_utils.c projections.c \
		key_hooks.c init.c hook_utils.c free_memory.c draw_menu.c

OBJS = ${SRCS:.c=.o}

LIBFT = libft
LIBFT_LIB = libft/libft.a
HEADER = fdf.h
MLX42_LIB = MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm

CC = cc
CFLAGS = -Wall -Wextra -Werror 

all: ${NAME}

%.o: %.c
	${CC} -c $< -o ${<:.c=.o}

${LIBFT_LIB}:
	make -C ${LIBFT}

${NAME}: ${LIBFT_LIB} ${OBJS} ${HEADER}
	${CC} ${OBJS} ${LIBFT_LIB} ${MLX42_LIB} -o ${NAME}

clean:
	make -C ${LIBFT} clean
	rm -f ${OBJS}

fclean: clean
	make -C ${LIBFT} fclean
	rm -f ${NAME}

re: fclean all

.PHONY:	all clean fclean re