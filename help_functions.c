/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <caking@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 15:21:35 by caking            #+#    #+#             */
/*   Updated: 2019/07/30 15:44:55 by caking           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_dublicate(int *array, int n)
{
	int		i;
	int		tmp;
	int		j;

	i = 0;
	while (i < n)
	{
		tmp = array[i];
		j = i + 1;
		while (j < n)
		{
			if (array[j] == tmp)
				ft_error(1);
			j++;
		}
		++i;
	}
}

void	ft_error(int n)
{
	ft_putstr("\033[0;31m");
	(n == 1) ? (ft_putstr("dublicate array\n")) : 0;

	exit(-1);
}