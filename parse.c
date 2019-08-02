/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <caking@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 14:21:54 by caking            #+#    #+#             */
/*   Updated: 2019/08/02 15:30:40 by caking           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void stack_done(t_struct *arr, char **result, int n)
{
    int i;
    int j;

    i = 0;
    j = 0;
    arr->a = (int*)malloc(sizeof(int) * n);
    arr->in_a = n;
    arr->in_b = 0;
    if(arr->argc == 1)
    {
        arr->in_a = n-1;
        i = 1;
    }
    if(arr->visualization != 0)
    {
         j--;
         arr->in_a--;
    }
    arr->n = arr->in_a;
    while(i < n)
    {
        arr->a[j] = ft_atoi(result[i]);
        j++;
        i++;
    }
    if(arr->argc == 1)
        n--;
}

void    ft_split(t_struct *arr, char *str)
{
    char **result;
    int i;
    int j;
    int n;

    result = (char **)malloc(sizeof(char *) * 10000);
    i = 0;
    j = 0;
    n = 0;
    if (!(str))
        return ;
    while(str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
        i++;
    while(str[i])
    {
        n = 0;
        result[j] = (char *)malloc(sizeof(char) * 10000);
        while(str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
            result[j][n++] = str[i++];
         j++; 
        while(str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
            i++;
    }
    stack_done(arr,result, j);
}