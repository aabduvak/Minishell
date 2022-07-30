# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 16:23:46 by aabduvak          #+#    #+#              #
#    Updated: 2022/07/31 02:07:20 by arelmas          ###   ########.fr        #
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

SRCS			= $(shell find sources -type f -name "*.c")
OBJS			= $(SRCS:sources/%.c=sources/bin/%.o)
USR				= $(shell echo $(USER))
LOG				= output.file

# Command and Flags

NAME			= minishell
CC				= gcc
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror -I/Users/$(USR)/readline/include
LDFLAGS			= -L/Users/$(USR)/readline/lib -lreadline
LIB				= ./libft/libft.a

# Directories

INC_FT			= ./libft/sources
INC_GN			= ./libft/GNL/sources
INC_PR			= ./libft/ft_printf/sources
INC_BL			= ./builtin/
INC				= ./includes/
BIN				= ./sources/bin/

# Rules


all : $(LIB) $(NAME)

$(LIB):
	@make -C ./libft

$(BIN):
	@mkdir $(BIN)

$(BIN)%.o: sources/%.c
	@mkdir -p $(shell dirname $@)
	@echo $(YELLOW) "Compiling..." $< $(END)
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_PR) -I$(INC_GN) -I$(INC_FT) -I$(INC)

$(NAME): $(BIN) $(OBJS)
	@echo $(YELLOW) "Building... $(NAME)" $(END)
	@$(CC) $(OBJS) $(LDFLAGS) -o $(NAME) $(LIB)
	@echo $(GREEN) "$(NAME) created successfully!\n" $(END)

# $< input files
# $@ output files
# in makefile used to create oputput files in their subfolder

clean :
	@echo $(YELLOW) "Removing object files...$(NAME)" $(END)
	@$(RM) $(OBJS)
	@echo $(RED) "All files deleted successfully!\n" $(END)

fclean : clean
	@echo $(YELLOW) "Removing $(NAME)..." $(END)
	@$(RM) $(NAME)
	@$(RM) $(BIN)
	@echo $(RED) "$(NAME) deleted successfully!\n" $(END)

ffclean: fclean
	@make fclean -C ./libft

norm :
	@norminette libft/
	@norminette sources
	@norminette includes/*.h

re : ffclean all

run : $(NAME)
	@./$(NAME)

leaks: $(NAME)
	@valgrind --log-file=$(LOG) --leak-check=yes --tool=memcheck ./$(NAME)  
	@cat $(LOG)

help :
	@echo "------------------------------------ <<HELP COMMAND>> ------------------------------------"
	@echo ""
	@echo "make            --------- compiles all *.c files and create libftprintf.a library"
	@echo "make clean      --------- cleans all *.o files in sources"
	@echo "make fclean 	   --------- cleans all *.o files in sources and libftprintf.a library"
	@echo "make re         --------- cleans all files and compiles again"
	@echo "make norm       --------- controls all *.c and *.h codes to norminette standart"
	@echo "make run        --------- compile and run program"
	@echo "make leaks      --------- checks all leaks in the program and creates output.file"

.PHONY: all clean fclean re run
