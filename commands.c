/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <caking@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 16:05:41 by caking            #+#    #+#             */
/*   Updated: 2019/07/30 16:10:35 by caking           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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