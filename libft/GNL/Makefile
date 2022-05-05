# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 16:43:54 by aabduvak          #+#    #+#              #
#    Updated: 2022/05/05 08:03:38 by aabduvak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLACK			=	"\033[0;30m"
RED				=	"\033[0;31m"
GREEN			=	"\033[0;32m"
YELLOW			=	"\033[0;33m"
CYAN			=	"\033[0;35m"
BLUE			=	"\033[0;36m"
WHITE			=	"\033[0;37m"
END				=	"\033[0;0m"

SRCS			= $(wildcard sources/*.c)
OBJS			= $(SRCS:.c=.o)

NAME			= get_next_line.a
CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror
LIB				= libftprintf.a

all : $(LIB) $(NAME)

$(LIB) :
	@make -C ../ft_printf	

$(NAME) : $(OBJS)
	@echo $(YELLOW) "Copying and archieving object files...$(NAME)" $(END)
	@cp ../ft_printf/$(LIB) ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo $(GREEN) "$(NAME) created successfully!\n" $(END)

.c.o :
	@echo $(YELLOW) "Compiling..." $< $(END)
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@echo $(YELLOW) "Removing object files..." $(END)
	@$(RM) $(OBJS)
	@echo $(RED) "All files deleted successfully!\n" $(END)

fclean : clean
	@echo $(YELLOW) "Removing $(NAME)..." $(END)
	@$(RM) $(NAME)
	@echo $(RED) "$(NAME) deleted successfully!\n" $(END)

norm :
	@norminette sources/*.[ch]

re : fclean all

help :
	@echo "------------------------------------ <<HELP COMMAND>> ------------------------------------"
	@echo ""
	@echo "make        --------- will compile all *.c files and create libft.a library"
	@echo "make clean  --------- will clean all *.o files in sources"
	@echo "make fclean --------- will clean all *.o files in sources and libft.a library"
	@echo "make re     --------- will clean all files and compiles again"
	@echo "make norm   --------- will control all *.c and *.h codes to norminette standart"
	@echo "            --------- if finds norminette error will break"

.PHONY: all clean fclean re .c.o