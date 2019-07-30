/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <caking@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 13:17:42 by caking            #+#    #+#             */
/*   Updated: 2019/07/30 17:00:23 by caking           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct			s_struct
{
	int					*a;
	int					*b;
	int					n;
	int					in_a;
	int					in_b;
	unsigned int		argc;
}						t_struct;

typedef struct          s_do
{
    char                *s;
    struct s_do         *next; 
}                       t_do;


void    ft_split(t_struct *arr, char *str);
void    stack_done(t_struct *arr, char **result, int n);
void	check_dublicate(int *array, int n);
void	ft_error(int n);
void	do_sa(t_struct *arr, int f);
void    do_something(t_struct *arr, char *op);
int		need_sort(int *arr, int in_a, int n);
void    go_push_swap(t_struct *arr);

#endif