# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caking <caking@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/29 16:31:21 by caking            #+#    #+#              #
#    Updated: 2019/07/31 18:13:19 by caking           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIB = -I libft/libft.h -L./libft -lft
PRINTF = -I ft_printf/include/ft_printf.h -L./ft_printf -l ftprintf

SRC = main.c \
		help_functions.c \
		commands.c \
		push_swap.c
		
OBJ = $(SRC:.c=.o)

HEADER = -I push_swap.h

all: $(NAME)
$(NAME): $(OBJ)
	make -C libft/
	make -C ft_printf/
	gcc -Wall -Wextra -Werror $(OBJ) -o $(NAME) $(LIB) $(PRINTF)
clean:
	rm -rf libft/*.o
	rm -rf ft_printf/temporary/*.o
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)
	rm -rf libft/libft.a
	rm -rf ft_printf/libftprintf.a
re: fclean all

debug:
	 gcc -ggdb main.c push_swap.c help_functions.c commands.c -I push_swap.h -I libft/libft.h -L./libft -lft
