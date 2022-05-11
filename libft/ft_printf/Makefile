# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabduvak <aabduvak@42ISTANBUL.COM.TR>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/19 17:06:01 by aabduvak          #+#    #+#              #
#    Updated: 2022/05/11 18:09:09 by aabduvak         ###   ########.fr        #
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

NAME			= libftprintf.a
CC				= gcc
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror 

# Directories

BIN				= bin/

all : $(BIN) $(NAME)

$(NAME) : $(OBJS)
	@echo $(YELLOW) "Archieving object files... $(NAME)" $(END)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo $(GREEN) "$(NAME) created successfully!\n" $(END)

$(BIN):
	@mkdir $(BIN)

$(BIN)%.o: sources/%.c
	@echo $(YELLOW) "Compiling..." $< $(END)
	@$(CC) $(CFLAGS) -c $< -o $@

# $< input files
# $@ output files
# in makefile used to create oputput files in their subfolder

clean :
	@echo $(YELLOW) "Removing object files...$(NAME)" $(END)
	@$(RM) $(OBJS)
	@echo $(RED) "All files deleted successfully!\n" $(END)

fclean : clean
	@echo $(YELLOW) "Removing $(NAME)..." $(END)
	@$(RM) $(BIN)
	@$(RM) $(NAME)
	@echo $(RED) "$(NAME) deleted successfully!\n" $(END)

norm :
	norminette sources/*.[ch]

re : fclean all

help :
	@echo "------------------------------------ <<HELP COMMAND>> ------------------------------------"
	@echo ""
	@echo "make            --------- compiles all *.c files and create libftprintf.a library"
	@echo "make bonus      --------- compiles all bonus functions and create libftprintf.a library"
	@echo "make clean      --------- cleans all *.o files in sources"
	@echo "make fclean 	   --------- cleans all *.o files in sources and libftprintf.a library"
	@echo "make re         --------- cleans all files and compiles again"
	@echo "make norm       --------- controls all *.c and *.h codes to norminette standart"
	@echo "                --------- if finds norminette error will break"

.PHONY: all clean fclean re help