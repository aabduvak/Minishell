# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 16:23:46 by aabduvak          #+#    #+#              #
#    Updated: 2022/05/05 07:38:29 by aabduvak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors

BLACK			=	"\033[0;30m"
RED				=	"\033[0;31m"
GREEN			=	"\033[0;32m"
YELLOW			=	"\033[0;33m"
CYAN			=	"\033[0;35m"
BLUE			=	"\033[0;36m"
WHITE			=	"\033[0;37m"
END				=	"\033[0;0m"

# Files

SRCS			= $(wildcard sources/*.c)
OBJS			= $(SRCS:.c=.o)

# Command and Flags

NAME			= minishell
CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror
LIB				= ./libft/libft.a

# Directories

INC_FT			= ./libft/sources
INC_GN			= ./libft/GNL/sources
INC_PR			= ./libft/ft_printf/sources
INC				= ./includes

all : $(LIB) ${NAME}

$(LIB):
	make -C ./libft

$(NAME) : ${OBJS}
	@echo $(YELLOW) "Building... $(NAME)" $(END)
	@$(CC) $(OBJS) -o $(NAME) $(LIB)
	@echo $(GREEN) "$(NAME) created successfully!\n" $(END)

.c.o:
	@echo $(YELLOW) "Compiling..." $< $(END)
	@${CC} ${CFLAGS} -c $< -o $@ -I$(INC_PR) -I$(INC_GN) -I$(INC_FT) -I$(INC)	

# $< input files
# $@ output files
# in makefile used to create oputput files in their subfolder

clean :
	@echo $(YELLOW) "Removing object files..." $(END)
	@${RM} ${OBJS}
	@echo $(RED) "All files deleted successfully!\n" $(END)

fclean : clean
	@echo $(YELLOW) "Removing $(NAME)..." $(END)
	@${RM} ${NAME}
	@echo $(RED) "$(NAME) deleted successfully!\n" $(END)

ffclean: fclean
	make fclean -C ./libft

norm :
	@norminette libft/
	@norminette sources/*.[ch]
	@norminette includes/

re : fclean all

run : $(NAME)
	@./$(NAME)

help :
	@echo "------------------------------------ <<HELP COMMAND>> ------------------------------------"
	@echo ""
	@echo "make            --------- compiles all *.c files and create libftprintf.a library"
	@echo "make clean      --------- cleans all *.o files in sources"
	@echo "make fclean 	   --------- cleans all *.o files in sources and libftprintf.a library"
	@echo "make re         --------- cleans all files and compiles again"
	@echo "make norm       --------- controls all *.c and *.h codes to norminette standart"
	@echo "                --------- if finds norminette error will break"

.PHONY: all clean fclean re run