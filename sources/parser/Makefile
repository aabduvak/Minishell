INC	=	-I ../../includes -I ../../libft/sources \
	       	-I ../../libft/ft_printf/sources -I ../../libft/GNL/sources
SRC	=	*.c \
	       	../env/*.c \
	       	../builtin/*.c \
		../converter/convert.c \
		../data_struct/*.c \
		../../libft/sources/ft_strncmp.c \
		../../libft/libft.a \
		../process/*.c
CC	=	gcc
CFLAG	=	-Wall -Wextra -Werror

all:
	${CC} ${SRC} ${INC} -o shell
