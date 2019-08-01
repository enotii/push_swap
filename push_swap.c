/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <caking@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 22:43:22 by caking            #+#    #+#             */
/*   Updated: 2019/08/01 16:32:27 by caking           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_dots(int a)
{
	while(a>=0)
	{
		ft_printf(".");
		a--;
	}
	ft_printf("\n");
}

void	ft_op(t_struct *s, t_do **head, char *src)
{
	t_do		*new;
	t_do		*point;
	int 		i;
	int			j;

	i = 0;
	j = 0;
	point = *head;
	if (s->visualization == 1 || s->visualization == 2)
	{
		printf("\x1b[32mstack <A>\t stack <B>\n");
	while(i < s->in_a || j < s->in_b)
	{
		if(i < s->in_a && j < s->in_b)
		printf("\x1b[32m   %d\t\t%d\n",s->a[i++],s->b[j++]);
		if(i < s->in_a && j == s->in_b)
		printf("\x1b[32m   %d\n",s->a[i++]);
		if(i == s->in_a && j < s->in_b)
		printf("\x1b[32ms\t   %d\n",s->b[j++]);
	}
	if(s->visualization == 1)
	getchar();
	system("clear");
	ft_printf("\x1b[35mCOMMAND IS --> %s\n",src);
	}
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

int		find_median(int *arr,int n, int f)
{
	int *tmp;
	int med;

	tmp = copy_array(arr,n);
	quicksort(tmp, 0 ,n - 1, f);
	med = (tmp[n / 2]);
	free(tmp);
	return(med);
}

int		what_about_med(int *arr, int n, int med, int f)
{
	int	i;

	i = 0;
	while(i < n)
	{
		if(f == 1 && arr[i] < med)
			return(1);
		if(f == 0 && arr[i] > med)
			return(1);
		i++;
	}
	return(0);
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
	while(op)
	{
		delete = op;
		ft_putstr("\x1b[35m");
		ft_putstr(op->s);
		ft_putstr("\n");
		op = op->next;
		ft_strdel(&delete->s);
		free(delete);
		arr->n_operation++;
	}
}

void    go_push_swap(t_struct *arr)
{
	t_do		*head;
	t_do		*point;
	int 		i;

	i = 0;
	head = (t_do*)malloc(sizeof(t_do));
	head->s = NULL;
	head->next = NULL;
	arr->n_operation = 0;
	if (arr->in_a > 3)
		ft_swap_from_a(arr, head, arr->in_a, 0);
	else
	 	ft_sort_three_with_nothing(arr, head);
	if(arr->visualization == 0)
	 print_result(head, arr);
	if(arr->visualization == 1 || arr->visualization == 2)
	{
		 printf("\x1b[32mstack <A>\t stack <B>\n");
		 while(i < arr->in_a)
		 printf("\x1b[32m   %d\n",arr->a[i++]);
	}
}