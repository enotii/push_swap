/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <caking@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 16:08:39 by caking            #+#    #+#             */
/*   Updated: 2019/07/29 18:22:19 by caking           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <stdio.h>

void    ft_split(char *str);
int     ft_atoi(const char *str);
void    stack_done(char **arr, int n);
void    sort_selection(int *arr, int i);
void    quick_sort(int *s_arr, int first, int last);
void    swap(int *arr,int n);
void    push(int *a, int *b, int na, int nb);
void    rotate(int *arr, int n);
void    push_swap(int *arr, int n);