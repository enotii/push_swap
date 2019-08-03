/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 15:21:35 by caking            #+#    #+#             */
/*   Updated: 2019/08/03 20:26:28 by caking           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quicksort(int *list, int low, int high, int i)
{
	int		pivot;
	int		j;
	int		temp;

	if (low < high)
	{
		pivot = low;
		i = low;
		j = high;
		while (i < j)
		{
			while (list[i] <= list[pivot] && i <= high)
				i++;
			while (list[j] > list[pivot] && j >= low)
				j--;
			(i < j) ? (temp = list[i]) : 0;
			(i < j) ? (list[i] = list[j]) : 0;
			(i < j) ? (list[j] = temp) : 0;
		}
		temp = list[j];
		list[j] = list[pivot];
		list[pivot] = temp;
		quicksort(list, low, j - 1, 0);
		quicksort(list, j + 1, high, 0);
	}
}

int		*copy_array(int *arr, int size)
{
	int *result;
	int i;

	result = (int *)malloc(sizeof(int) * size);
	i = 0;
	while(i < size)
	{
		result[i] = arr[i];
		i++;
	}
	return(result);
}

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
	(n == 1) ? (ft_putstr("duplicate array\n")) : 0;
	(n == 2) ? (ft_putstr("this is not array\n")) : 0;
	(n == 3) ? (ft_putstr("usage with arg")) : 0;
	(n == 4) ? (ft_putstr("this is not valid oparations")) : 0;
	(n == 5) ? (ft_putstr("bigger max int or min int")) : 0;
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

int		ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' ||
			c == '\r' || c == '\f' || c == '\v')
		return (1);
	else
		return (0);
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

void    do_something(t_struct *arr, char *op)
{
	int f;

	f = 0;
    (ft_strcmp(op,"sa") == 0) ? do_sa(arr,1) : 0;
	(ft_strcmp(op, "sa") == 0 || ft_strcmp(op, "sb") == 0) ? (f++) : 0;
	(ft_strcmp(op, "ss") == 0 || ft_strcmp(op, "pa") == 0) ? (f++) : 0;
	(ft_strcmp(op, "pb") == 0 || ft_strcmp(op, "ra") == 0) ? (f++) : 0;
	(ft_strcmp(op, "rb") == 0 || ft_strcmp(op, "rr") == 0) ? (f++) : 0;
	(ft_strcmp(op, "rra") == 0 || ft_strcmp(op, "rrb") == 0) ? (f++) : 0;
	(ft_strcmp(op, "rrr") == 0) ? (f++) : 0;
	(ft_strcmp(op, "sb") == 0) ? ft_swap_two_first(arr, 2) : 0;
	(ft_strcmp(op, "ss") == 0) ? ft_swap_two_first(arr, 1) : 0;
	(ft_strcmp(op, "ss") == 0) ? ft_swap_two_first(arr, 2) : 0;
	(ft_strcmp(op, "pa") == 0) ? ft_put(arr, 1) : 0;
	(ft_strcmp(op, "pb") == 0) ? ft_put(arr, 2) : 0;
	(ft_strcmp(op, "ra") == 0) ? ft_shift_up(arr->a, arr->in_a) : 0;
	(ft_strcmp(op, "rb") == 0) ? ft_shift_up(arr->b, arr->in_b) : 0;
	(ft_strcmp(op, "rr") == 0) ? ft_shift_up(arr->a, arr->in_a) : 0;
	(ft_strcmp(op, "rr") == 0) ? ft_shift_up(arr->b, arr->in_b) : 0;
	(ft_strcmp(op, "rra") == 0) ? ft_shift_down(arr->a, arr->in_a) : 0;
	(ft_strcmp(op, "rrb") == 0) ? ft_shift_down(arr->b, arr->in_b) : 0;
	(ft_strcmp(op, "rrr") == 0) ? ft_shift_down(arr->a, arr->in_a) : 0;
	(ft_strcmp(op, "rrr") == 0) ? ft_shift_down(arr->b, arr->in_b) : 0;
	(f != 1) ? (ft_error(4)) : 0;
}