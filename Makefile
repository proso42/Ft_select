# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: proso <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/27 13:41:20 by proso             #+#    #+#              #
#    Updated: 2017/05/27 16:34:42 by proso            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

SRC = Sources/arrow.c \
      Sources/change_terminal.c \
	  Sources/func_tools_2.c \
	  Sources/func_tools.c \
	  Sources/get_size_max.c \
	  Sources/main.c \
	  Sources/print_arg_slc.c \
	  Sources/print_tab_col.c \
	  Sources/restore_elem.c \
	  Sources/search.c \
	  Sources/signal_2.c \
	  Sources/signal.c \
	  Sources/space_and_delete.c \
	  Sources/use_keyboard.c

CC = gcc

FLAGS = -Wall -Werror -Wextra

INCLUDE = Includes/ft_select.h

LIB = Libft/libft.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o:%.c
	@$(CC) $(FLAGS) -I./$(INCLUDE) -o $@ -c $<
	@Sources/p_bar_select $<
	@sleep 0.05

make_lib:
	@make -C Libft/
	@clear
	@echo "\x1b[33m\x1b[1mMaking executable... ⏳\x1b[0m"
	@sleep 1

$(NAME): make_lib $(OBJ)
	@$(CC) $(FLAGS) -o $(NAME) $(LIB) $(OBJ) -ltermcap
	@sleep 1
	@clear
	@echo "\x1b[32m\x1b[1mExecutable sucessfully created ✓\x1b[0m"

clean:
	@make clean -C Libft/
	@rm -f $(OBJ)
	@echo "\x1b[31m\x1b[1mAll objects deleted ✖\x1b[0m"

fclean: clean
	@make fclean -C Libft/
	@rm -f $(NAME)
	@echo "\x1b[31m\x1b[1mExecutable deleted ✖\x1b[0m"

re: fclean all
