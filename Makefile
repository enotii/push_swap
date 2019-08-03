# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caking <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/29 16:31:21 by caking            #+#    #+#              #
#    Updated: 2019/08/03 23:35:38 by caking           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = push_swap

NAME2 = checker

LIB = -I libft/libft.h -L./libft -lft
PRINTF = -I ft_printf/include/ft_printf.h -L./ft_printf -l ftprintf

SRC =   help_function3.c \
		help_functions2.c \
		help_functions.c \
		commands.c \
		push_swap.c \
		parse.c \
		get_next_line.c 
		
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

debugc:
	 gcc -ggdb checker_main.c push_swap.c help_functions.c commands.c get_next_line.c parse.c -I push_swap.h -I libft/libft.h -L./libft -lft $(PRINTF)

debugp:
	 gcc -ggdb main.c push_swap.c help_functions.c commands.c get_next_line.c parse.c -I push_swap.h -I libft/libft.h -L./libft -lft $(PRINTF)

val:
	valgrind --leak-check=full ./checker 4 3 2 1

norm:
	norminette -R CheckForbiddenSourceHeader *
