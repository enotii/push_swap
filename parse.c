/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 14:21:54 by caking            #+#    #+#             */
/*   Updated: 2019/08/03 22:44:46 by caking           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_done(t_struct *arr, char **result, int n)
{
	int i;
	int j;

	i = 0;
	j = 0;
	arr->a = (int*)malloc(sizeof(int) * n);
	arr->in_a = n;
	arr->in_b = 0;
	if (arr->argc == 1)
	{
		arr->in_a = n - 1;
		i = 1;
	}
	if (arr->visualization != 0)
	{
		j--;
		arr->in_a--;
	}
	arr->n = arr->in_a;
	while (i < n)
		arr->a[j++] = ft_atoi_ssize(result[i++]);
	(arr->argc == 1) ? n-- : 0;
}

void	ft_split(t_struct *arr, char *str)
{
	char	**result;
	int		i;
	int		j;
	int		n;

	result = (char **)malloc(sizeof(char *) * 10000);
	i = 0;
	j = 0;
	n = 0;
	if (!(str))
		return ;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		i++;
	while (str[i])
	{
		n = 0;
		result[j] = (char *)malloc(sizeof(char) * 10000);
		while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			result[j][n++] = str[i++];
		j++;
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
	}
	stack_done(arr, result, j);
}

void	do_something(t_struct *arr, char *op)
{
	int f;

	f = 0;
	(ft_strcmp(op, "sa") == 0) ? do_sa(arr, 1) : 0;
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
