/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 15:21:35 by caking            #+#    #+#             */
/*   Updated: 2019/08/03 22:27:17 by caking           ###   ########.fr       */
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
	while (i < size)
	{
		result[i] = arr[i];
		i++;
	}
	return (result);
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
	(n == 1) ? (ft_putstr("Error\n")) : 0;
	(n == 2) ? (ft_putstr("Error\n")) : 0;
	(n == 3) ? (ft_putstr("Error\n")) : 0;
	(n == 4) ? (ft_putstr("Error\n")) : 0;
	(n == 5) ? (ft_putstr("Error\n")) : 0;
	exit(-1);
}
