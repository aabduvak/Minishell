# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabduvak <aabduvak@42ISTANBUL.COM.TR>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/24 01:44:57 by aabduvak          #+#    #+#              #
#    Updated: 2022/05/11 18:05:26 by aabduvak         ###   ########.fr        #
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
OBJS			= $(SRCS:sources/%.c=bin/%.o)

# Command and Flags

NAME			= libft.a
CC				= gcc
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror
LIB				= GNL/get_next_line.a

# Directories

BIN				= bin/
INCS			= ./libft.h

# Rules

all : $(LIB) $(BIN) $(NAME)

$(LIB):
	@make -C ./GNL

$(NAME) : $(OBJS)
	@echo $(YELLOW) "Copying and archieving object files...$(NAME)" $(END)
	@cp $(LIB) ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo $(GREEN) "$(NAME) created successfully!\n" $(END)

$(BIN):
	@mkdir $(BIN)

$(BIN)%.o: sources/%.c
	@echo $(YELLOW) "Compiling..." $< $(END)
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@echo $(YELLOW) "Removing object files...$(NAME)" $(END)
	@$(RM) $(OBJS)
	@echo $(RED) "All files deleted successfully!\n" $(END)

fclean : clean
	@make fclean -C ./GNL
	@make fclean -C ./ft_printf
	@echo $(YELLOW) "Removing $(NAME)..." $(END)
	@$(RM) $(NAME)
	@$(RM) $(BIN)
	@echo $(RED) "$(NAME) deleted successfully!\n" $(END)

norm :
	@make norm -C ft_printf/
	@make norm -C GNL/
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

.PHONY: all clean fclean re help