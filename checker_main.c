/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 16:34:42 by caking            #+#    #+#             */
/*   Updated: 2019/08/03 23:05:31 by caking           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	validate_checker(t_struct *new, int argc, char **argv)
{
	new->visualization = 0;
	if (ft_strcmp(argv[1], "-v") == 0)
		new->visualization = 1;
	if (ft_strcmp(argv[1], "-c") == 0)
		new->visualization = 2;
	if (argc == 2)
		ft_split(new, argv[1]);
	else if (argc > 2)
	{
		new->argc = 1;
		stack_done(new, argv, argc);
	}
}

int		main(int argc, char **argv)
{
	t_struct		*new;
	char			*src;

	src = NULL;
	(argc == 1) ? (exit(-1)) : 0;
	(argv[1][0] == '\0') ? (ft_error(2)) : 0;
	new = (t_struct*)malloc(sizeof(t_struct));
	validate_checker(new, argc, argv);
	check_dublicate(new->a, new->n);
	src = NULL;
	new->n_operation = 0;
	while (get_next_line(0, &src) > 0)
	{
		do_something(new, src);
		free(src);
	}
	(need_sort(new->a, new->in_a, new->n) == 0) ?
	(ft_putstr("\033[0;31mKO\n\e[0m")) : (ft_putstr("\033[0;32mOK\n\e[0m"));
	return (0);
}
