# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caking <caking@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/29 16:31:21 by caking            #+#    #+#              #
#    Updated: 2019/07/29 17:03:48 by caking           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

all: $(NAME)
$(NAME):
	gcc -Wall -Wextra -Werror *.c
clean:
	rm -rf $(NAME)
fclean: clean

re: fclean all

debug:
	 gcc -ggdb *.c
