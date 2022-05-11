# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabduvak <aabduvak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 00:56:02 by aabduvak          #+#    #+#              #
#    Updated: 2022/05/12 01:19:26 by aabduvak         ###   ########.fr        #
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

SRCS			= $(wildcard *.c)
OBJS			= $(SRCS:%.c=bin/%.o)

# Command and Flags

NAMES			= echo cd pwd export unset env exit 
CC				= gcc
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror

# Directories

INC_FT			= ../libft/sources
INC_GN			= ../libft/GNL/sources
INC_PR			= ../libft/ft_printf/sources
INC				= ../includes
BIN				= bin/
ECO 			= echo

# Rules

all : $(BIN) $(NAMES)
	

$(BIN):
	@mkdir $(BIN)

$(NAMES):  $(OBJS)
	@echo $(YELLOW) "Building...$(ECO)" $(END)
	@$(CC) $(OBJS) -o $(ECO) $(LIB)
	@echo $(GREEN) "$(ECO) created successfully!\n" $(END)
	

$(BIN)%.o: %.c
	@echo $(YELLOW) "Compiling..." $< $(END)
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_PR) -I$(INC_GN) -I$(INC_FT) -I$(INC)

# $< input files
# $@ output files
# in makefile used to create oputput files in their subfolder

clean :
	@echo $(YELLOW) "Removing object files...$(NAMES)" $(END)
	@$(RM) $(OBJS)
	@echo $(RED) "All files deleted successfully!\n" $(END)

fclean : clean
	@echo $(YELLOW) "Removing $(NAMES)..." $(END)
	@$(RM) $(NAMES)
	@$(RM) $(BIN)
	@echo $(RED) "$(NAMES) deleted successfully!\n" $(END)

ffclean: fclean
	@make fclean -C ./libft

norm :
	@norminette libft/
	@norminette sources/*.[ch]
	@norminette includes/*.[ch]

re : fclean all

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