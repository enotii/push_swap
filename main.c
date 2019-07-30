/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <caking@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 13:16:53 by caking            #+#    #+#             */
/*   Updated: 2019/07/30 15:45:04 by caking           ###   ########.fr       */
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
    arr->n = arr->in_a;
    if(arr->argc == 1)
        i = 1;
    while(i < n)
    {
        arr->a[j] = ft_atoi(result[i]);
        j++;
        i++;
    }
    i = 0;
    if(arr->argc == 1)
        n--;
     while(i < n)
    {
        printf("%d\t",arr->a[i]);
        i++;
    }
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


int main(int argc, char *argv[])
{
    t_struct    *arr;
    if(argc == 1)
        return(0);
    arr = (t_struct*)malloc(sizeof(t_struct));
    if(argc == 2)
    {
        ft_split(arr,argv[1]);
        arr->argc = 0;
    }
    else if(argc > 2)
    {
        arr->argc = 1;
        stack_done(arr,argv,argc);
    }
    check_dublicate(arr->a,arr->n);
    return 0;
}
