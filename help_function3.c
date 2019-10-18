/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_function3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <caking@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 23:19:19 by caking            #+#    #+#             */
/*   Updated: 2019/10/18 20:13:43 by caking           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		tmp = tmp * sign;
	if (tmp > 2147483647 || tmp < -2147483648)
		ft_error(5);
	return ((int)tmp);
}
