# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caking <caking@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/29 16:31:21 by caking            #+#    #+#              #
#    Updated: 2019/08/01 16:47:29 by caking           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = push_swap

NAME2 = checker

LIB = -I libft/libft.h -L./libft -lft
PRINTF = -I ft_printf/include/ft_printf.h -L./ft_printf -l ftprintf

SRC =   help_functions.c \
		commands.c \
		push_swap.c
		
OBJ = $(SRC:.c=.o)

HEADER = -I push_swap.h

all: $(NAME1) $(NAME2)

$(NAME1):  $(OBJ)
	make -C libft/
	make -C ft_printf/
	gcc -Wall -Wextra -Werror $(OBJ) main.c -o $(NAME1) $(LIB) $(PRINTF)

$(NAME2):  $(OBJ)
	gcc -Wall -Wextra -Werror $(OBJ) checker_main.c -o $(NAME2) $(LIB) $(PRINTF)

clean:
	rm -rf libft/*.o
	rm -rf ft_printf/temporary/*.o
	rm -rf *.o main.o checker_main.o

fclean: clean
	rm -rf $(NAME1) $(NAME2)
	rm -rf libft/libft.a
	rm -rf ft_printf/libftprintf.a

re: fclean all

debug:
	 gcc -ggdb main.c push_swap.c help_functions.c commands.c -I push_swap.h -I libft/libft.h -L./libft -lft
