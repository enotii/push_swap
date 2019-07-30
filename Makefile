# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caking <caking@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/29 16:31:21 by caking            #+#    #+#              #
#    Updated: 2019/07/30 16:55:54 by caking           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIB = -I libft/libft.h -L./libft -lft

SRC = main.c \
		help_functions.c\
		commands.c\
		push_swap.c
		


OBJ = $(SRC:.c=.o)

HEADER = -I push_swap.h

all: $(NAME)
$(NAME): $(OBJ)
	make -C libft/
	gcc -Wall -Wextra -Werror $(OBJ) -o  $(NAME) $(LIB)
clean:
	rm -rf libft/*.o
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)
	rm -rf libft/libft.a
re: fclean all

debug:
	 gcc -ggdb main.c push_swap.c help_functions.c commands.c -I push_swap.h -I libft/libft.h -L./libft -lft
