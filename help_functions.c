/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <caking@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 15:21:35 by caking            #+#    #+#             */
/*   Updated: 2019/07/31 16:53:45 by caking           ###   ########.fr       */
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

}