/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 22:39:26 by caking            #+#    #+#             */
/*   Updated: 2019/08/03 23:25:21 by caking           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_from_a(t_struct *s, t_do *op, int len, int i)
{
	int		med;
	int		rotate;
	int		push;

	push = 0;
	rotate = 0;
	(len <= 3) ? (ft_sort_three(s, op, 1)) : 0;
	if (len <= 3)
		return ;
	med = find_median(s->a, len, 1);
	while (what_about_med(s->a, len - i, med, 1) && i++ < len)
	{
		(s->a[0] < med) ? (push++) : (rotate++);
		(s->a[0] < med) ? (ft_op(s, &op, "pb")) : (ft_op(s, &op, "ra"));
	}
	if (rotate > (s->in_a / 2) && s->in_a > 3)
		while (rotate++ < s->in_a)
			ft_op(s, &op, "ra");
	else if (s->in_a > 3)
		while (rotate--)
			ft_op(s, &op, "rra");
	ft_swap_from_a(s, op, (len - push), 0);
	ft_swap_from_b(s, op, push, 0);
	while (push--)
		ft_op(s, &op, "pa");
}

void	ft_sort_three_with_nothing(t_struct *arr, t_do *head)
{
	while (!need_sort(arr->a, arr->in_a, arr->in_a) && arr->in_a <= 3)
	{
		if (arr->a[0] > arr->a[1])
		{
			if (arr->in_a > 2 && arr->a[0] < arr->a[arr->in_a - 1])
				ft_op(arr, &head, "sa");
			else
				ft_op(arr, &head, "ra");
		}
		else if (!need_sort(arr->a, arr->in_a, arr->in_a))
		{
			if (arr->a[0] < arr->a[1])
			{
				if (arr->in_a > 2 && arr->a[0] > arr->a[arr->in_a - 1])
					ft_op(arr, &head, "rra");
				else
					ft_op(arr, &head, "ra");
			}
		}
	}
}

void	print_result(t_do *op, t_struct *arr)
{
	t_do *delete;

	while (op)
	{
		delete = op;
		ft_putstr(op->s);
		ft_putstr("\n");
		op = op->next;
		ft_strdel(&delete->s);
		free(delete);
		arr->n_operation++;
	}
}

void	go_push_swap(t_struct *arr)
{
	int			i;
	t_do		*head;
	t_do		*point;

	i = 0;
	head = (t_do*)malloc(sizeof(t_do));
	head->s = NULL;
	head->next = NULL;
	arr->n_operation = 0;
	if (arr->in_a > 3)
		ft_swap_from_a(arr, head, arr->in_a, 0);
	else
		ft_sort_three_with_nothing(arr, head);
	if (arr->visualization == 0)
		print_result(head, arr);
	if (arr->visualization == 1 || arr->visualization == 2)
	{
		ft_printf("\x1b[32mstack <A>\t stack <B>\n");
		while (i < arr->in_a)
			ft_printf("\x1b[32m   %d\n", arr->a[i++]);
	}
}

void	vizual(t_struct *s, char *src)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	ft_printf("\x1b[32mstack <A>\t stack <B>\n");
	while (i < s->in_a || j < s->in_b)
	{
		if (i < s->in_a && j < s->in_b)
			ft_printf("\x1b[32m   %d\t\t%d\n", s->a[i++], s->b[j++]);
		if (i < s->in_a && j == s->in_b)
			ft_printf("\x1b[32m   %d\n", s->a[i++]);
		if (i == s->in_a && j < s->in_b)
			ft_printf("\x1b[32ms\t   %d\n", s->b[j++]);
	}
	if (s->visualization == 1)
		getchar();
	system("clear");
	ft_printf("\x1b[35mCOMMAND IS --> %s\n", src);
}
