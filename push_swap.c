/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 22:43:22 by caking            #+#    #+#             */
/*   Updated: 2019/08/03 23:01:36 by caking           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_op(t_struct *s, t_do **head, char *src)
{
	t_do		*new;
	t_do		*point;

	point = *head;
	if (s->visualization == 1 || s->visualization == 2)
		vizual(s, src);
	do_something(s, src);
	if (point->s == NULL)
		point->s = ft_strdup(src);
	else
	{
		while (point->next != NULL)
			point = point->next;
		new = (t_do*)malloc(sizeof(t_do));
		new->s = ft_strdup(src);
		new->next = NULL;
		point->next = new;
	}
	*head = point;
}

void	ft_sort_three(t_struct *s, t_do *op, int f)
{
	if (f == 1)
	{
		(s->in_a > 1 && s->a[0] > s->a[1]) ? (ft_op(s, &op, "sa")) : 0;
		if (s->in_a > 2 && s->a[1] > s->a[2])
		{
			ft_op(s, &op, "ra");
			ft_op(s, &op, "sa");
			ft_op(s, &op, "rra");
		}
		(s->in_a > 1 && s->a[0] > s->a[1]) ? (ft_op(s, &op, "sa")) : 0;
	}
	else
	{
		(s->in_b > 1 && s->b[0] < s->b[1]) ? (ft_op(s, &op, "sb")) : 0;
		if (s->in_b > 2 && s->b[1] < s->b[2])
		{
			ft_op(s, &op, "rb");
			ft_op(s, &op, "sb");
			ft_op(s, &op, "rrb");
		}
		(s->in_b > 1 && s->b[0] < s->b[1]) ? (ft_op(s, &op, "sb")) : 0;
	}
}

int		find_median(int *arr, int n, int f)
{
	int *tmp;
	int med;

	tmp = copy_array(arr, n);
	quicksort(tmp, 0, n - 1, f);
	med = (tmp[n / 2]);
	free(tmp);
	return (med);
}

int		what_about_med(int *arr, int n, int med, int f)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (f == 1 && arr[i] < med)
			return (1);
		if (f == 0 && arr[i] > med)
			return (1);
		i++;
	}
	return (0);
}

void	ft_swap_from_b(t_struct *arr, t_do *op, int len, int i)
{
	int		med;
	int		rotate;
	int		push;

	push = 0;
	rotate = 0;
	(len <= 3) ? (ft_sort_three(arr, op, 0)) : 0;
	if (len <= 3)
		return ;
	med = find_median(arr->b, len, 0);
	while (what_about_med(arr->b, len - i, med, 0) && i++ < len)
	{
		(arr->b[0] > med) ? (push++) : (rotate++);
		(arr->b[0] > med) ? (ft_op(arr, &op, "pa")) : (ft_op(arr, &op, "rb"));
	}
	ft_swap_from_a(arr, op, push, 0);
	if (rotate > (arr->in_b / 2) && arr->in_b > 3)
		while (rotate++ < arr->in_b)
			ft_op(arr, &op, "rb");
	else if (arr->in_b > 3)
		while (rotate--)
			ft_op(arr, &op, "rrb");
	ft_swap_from_b(arr, op, (len - push), 0);
	while (push--)
		ft_op(arr, &op, "pb");
}
