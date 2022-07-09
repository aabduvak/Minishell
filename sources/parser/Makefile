INC	=	-I ../../includes -I ../../libft/sources \
	       	-I ../../libft/ft_printf/sources -I ../../libft/GNL/sources
SRC	=	a.c parse_line.c strings_bzero.c parse_quote.c buf_over.c parse_bop.c strings_join.c check_built_op.c ../env/*.c ../builtin/*.c  ../converter/convert.c ../data_struct/*.c ../../libft/libft.a ../process/exec_checker.c
CC	=	gcc
CFLAG	=	-Wall -Wextra -Werror

all:
	${CC} ${SRC} ${INC} -o shell
