/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 22:43:22 by caking            #+#    #+#             */
/*   Updated: 2019/07/30 22:51:42 by caking           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_op(t_struct *s, t_do **head, char *src)
{
	t_do		*new;
	t_do		*point;

	point = *head;
	//ft_valid_operation(s, src);
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

void	ft_swap_from_a(t_struct *s, t_do *op, int len, int i)
{
	int		med;
	int		rot;
	int		push;

	push = 0;
	rot = 0;
	(len <= 3) ? (ft_sort_three(s, op, 1)) : 0;
	// if (len <= 3)
	// 	return ;
	// med = ft_find_med(s->a, len, 1);
	// while (ft_is_lower_or_bigger_then_med(s->a, len - i, med, 1) && i++ < len)
	// {
	// 	(s->a[0] < med) ? (push++) : (rot++);
	// 	(s->a[0] < med) ? (ft_op(s, &op, "pb")) : (ft_op(s, &op, "ra"));
	// }
	// if (rot > (s->in_a / 2) && s->in_a > 3)
	// 	while (rot++ < s->in_a)
	// 		ft_op(s, &op, "ra");
	// else if (s->in_a > 3)
	// 	while (rot--)
	// 		ft_op(s, &op, "rra");
	// ft_swap_from_a(s, op, (len - push), 0);
	// ft_swap_from_b(s, op, push, 0);
	// while (push--)
	// 	ft_op(s, &op, "pa");
}

void    go_push_swap(t_struct *arr)
{
	t_do		*head;
	t_do		*point;

	head = (t_do*)malloc(sizeof(t_do));
	head->s = NULL;
	head->next = NULL;
	arr->n_operation = 0;
	if (arr->in_a > 3)
		ft_swap_from_a(arr, head, arr->in_a, 0);
	// else
	// 	ft_sort(arr, head);
	// ft_operation_optimize(head, point, 1, 0);
	// ft_print_and_free(head, arr);
}