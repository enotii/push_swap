/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 16:05:41 by caking            #+#    #+#             */
/*   Updated: 2019/08/03 22:38:05 by caking           ###   ########.fr       */
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

void	ft_put_a(t_struct *src)
{
	int		*res;

	res = (int*)malloc(sizeof(int) * (src->in_a + 1));
	ft_copy_i_a(&res, src->a, src->in_a);
	src->a = res;
	ft_shift_down(src->a, (src->in_a + 1));
	src->a[0] = src->b[0];
	ft_shift_up(src->b, src->in_b);
	src->in_b--;
	src->in_a++;
	if (src->in_b != 0)
	{
		res = (int*)malloc(sizeof(int) * src->in_b);
		ft_copy_i_a(&res, src->b, src->in_b);
		src->b = res;
	}
	else
		free(src->b);
}

void	ft_swap_two_first(t_struct *src, int f)
{
	int		*tmp;
	int		t;

	tmp = NULL;
	(f == 1 && src->in_a > 1) ? (tmp = src->a) : 0;
	(f == 2 && src->in_b > 1) ? (tmp = src->b) : 0;
	if (tmp != NULL)
	{
		t = tmp[0];
		tmp[0] = tmp[1];
		tmp[1] = t;
		(f == 1) ? (src->a = tmp) : 0;
		(f != 1) ? (src->b = tmp) : 0;
	}
}


int		ft_atoi_ssize(char *src)
{
	ssize_t		tmp;
	ssize_t		sign;

	tmp = 0;
	sign = 1;
	while (ft_isspace(*src))
		src++;
	if (*src == '-')
		sign = -1;
	if (*src == '-' || *src == '+')
		src++;
	while (ft_isdigit(*src))
	{
		tmp *= 10;
		tmp += *src - '0';
		src++;
	}
	if (*src != '\0' && *src != '-' && !ft_isdigit(*src))
		ft_error(5);
	tmp = tmp * sign;
	if (tmp > 2147483647 || tmp < -2147483648)
		ft_error(5);
	return ((int)tmp);
}
