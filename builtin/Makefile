# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabduvak <aabduvak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 00:56:02 by aabduvak          #+#    #+#              #
#    Updated: 2022/05/12 11:52:26 by aabduvak         ###   ########.fr        #
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

SRCS_ECHO		= echo.c
OBJS_ECHO		= $(SRCS_ECHO:%.c=bin/%.o)
SRCS_PWD		= pwd.c
OBJS_PWD		= $(SRCS_ENV:%.c=bin/%.o)
SRCS_ENV		= pwd.c
OBJS_ENV		= $(SRCS_ENV:%.c=bin/%.o)

# Executables

NAME_ECHO		= echo
NAME_PWD		= pwd
NAME_ENV		= env

# Command and Flags

CC				= gcc
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror

# Directories

INC_FT			= ../libft/sources
INC_GN			= ../libft/GNL/sources
INC_PR			= ../libft/ft_printf/sources
INC				= ../includes
BIN				= bin/
LIB				= ../libft/libft.a

# Rules

all : $(LIB) $(NAME_ECHO) $(NAME_PWD)

$(LIB):
	@make -C ../libft

$(BIN):
	@mkdir $(BIN)

$(NAME_ECHO): $(BIN) $(OBJS_ECHO)
	@echo $(YELLOW) "Building...$(NAME_ECHO)" $(END)
	@$(CC) $(OBJS_ECHO) -o $(NAME_ECHO) $(LIB)
	@echo $(GREEN) "$(NAME_ECHO) created successfully!\n" $(END)

$(NAME_PWD): $(BIN) $(OBJS_PWD)
	@echo $(YELLOW) "Building...$(NAME_PWD)" $(END)
	@$(CC) $(OBJS_PWD) -o $(NAME_PWD) $(LIB)
	@echo $(GREEN) "$(NAME_PWD) created successfully!\n" $(END)

$(NAME_ENV): $(BIN) $(OBJS_ENV)
	@echo $(YELLOW) "Building...$(NAME_ENV)" $(END)
	@$(CC) $(OBJS_ENV) -o $(NAME_ENV) $(LIB)
	@echo $(GREEN) "$(NAME_ENV) created successfully!\n" $(END)

$(BIN)%.o: %.c
	@echo $(YELLOW) "Compiling..." $< $(END)
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_PR) -I$(INC_GN) -I$(INC_FT) -I$(INC)

# $< input files
# $@ output files
# in makefile used to create oputput files in their subfolder

clean :
	@echo $(YELLOW) "Removing object files..." $(END)
	@$(RM) $(OBJS_ECHO) $(OBJS_PWD) $(OBJS_ENV)
	@echo $(RED) "All files deleted successfully!\n" $(END)

fclean : clean
	@echo $(YELLOW) "Removing $(NAME_ECHO) $(NAME_PWD) $(NAME_ENV)..." $(END)
	@$(RM) $(NAME_ECHO)
	@$(RM) $(NAME_PWD)
	@$(RM) $(NAME_ENV)
	@$(RM) $(BIN)
	@echo $(RED) "Executables deleted successfully!\n" $(END)

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