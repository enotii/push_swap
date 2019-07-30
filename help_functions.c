/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 15:21:35 by caking            #+#    #+#             */
/*   Updated: 2019/07/30 22:43:02 by caking           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_dublicate(int *array, int n)
{
	int		i;
	int		tmp;
	int		j;

	i = 0;
	if(n == 1)
		ft_error(2);
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
	ft_putstr("\x1b[35m");
	(n == 1) ? (ft_putstr("duplicate array\n")) : 0;
	(n == 2) ? (ft_putstr("this is not array\n")) : 0;

	exit(-1);
}

int		need_sort(int *arr, int in_a, int n)
{
	int	i;

	i = 0;
	if (in_a < n)
		return (0);
	if (in_a == n && n == 1)
		return (1);
	while (i < (n - 1))
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}
void    do_something(t_struct *arr, char *op)
{
    (ft_strcmp(op,"sa") == 0) ? do_sa(arr,1) : 0;

}