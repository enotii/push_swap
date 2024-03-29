/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 16:05:41 by caking            #+#    #+#             */
/*   Updated: 2019/08/03 22:47:15 by caking           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_copy_i_a(int **t, int *src, int n)
{
	int		i;
	int		*point;

	if (n != 0)
	{
		i = 0;
		point = *t;
		while (i < n)
		{
			point[i] = src[i];
			i++;
		}
		free(src);
		*t = point;
	}
}

void	do_sa(t_struct *arr, int f)
{
	int		*tmp;
	int		t;

	tmp = NULL;
	(f == 1 && arr->in_a > 1) ? (tmp = arr->a) : 0;
	(f == 2 && arr->in_b > 1) ? (tmp = arr->b) : 0;
	if (tmp != NULL)
	{
		t = tmp[0];
		tmp[0] = tmp[1];
		tmp[1] = t;
		(f == 1) ? (arr->a = tmp) : 0;
		(f != 1) ? (arr->b = tmp) : 0;
	}
}

void	ft_shift_down(int *src, int n)
{
	int		i;
	int		j;
	int		tmp;

	if (n <= 1)
		return ;
	i = 0;
	j = n - 1;
	tmp = src[j];
	while (i <= j)
	{
		src[j] = (j == 0) ? tmp : src[j - 1];
		j--;
	}
}

void	ft_shift_up(int *src, int n)
{
	int		i;
	int		tmp;

	if (n <= 1)
		return ;
	i = 0;
	tmp = src[0];
	while (i < n)
	{
		src[i] = (i + 1 == n) ? tmp : src[i + 1];
		i++;
	}
}

void	ft_put(t_struct *src, int f)
{
	int	*res;

	(f == 1 && src->in_b > 0) ? (ft_put_a(src)) : 0;
	if (f == 2 && src->in_a > 0)
	{
		res = (int*)malloc(sizeof(int) * (src->in_b + 1));
		ft_copy_i_a(&res, src->b, src->in_b);
		src->b = res;
		ft_shift_down(src->b, src->in_b + 1);
		src->b[0] = src->a[0];
		ft_shift_up(src->a, src->in_a);
		src->in_a--;
		src->in_b++;
		if (src->in_a != 0)
		{
			res = (int*)malloc(sizeof(int) * src->in_a);
			ft_copy_i_a(&res, src->a, src->in_a);
			src->a = res;
		}
		else
			free(src->a);
	}
}
