/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <caking@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 13:44:33 by caking            #+#    #+#             */
/*   Updated: 2019/07/29 18:33:53 by caking           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_split(char *str)
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
    stack_done(result , j);
}
void  copy_arr(int *arr, int n)
{
    int *tmp;
    int i;

    tmp =(int*)malloc(n * sizeof(int));
    i = 0;
    while(arr[i] && i < n)
    {
        tmp[i] = arr[i];
        i++;
    }
    quick_sort(tmp, 0, n-1);
    push_swap(tmp, n);
}

void stack_done(char **arr, int n)
{
    int i;
    int *stack;

    i = 0;
    stack = (int*)malloc(n * sizeof(int));
    while(i < n)
    {
        stack[i] = ft_atoi(arr[i]);
       // printf("%d\n",stack[i]);
        i++;
    }
    copy_arr(stack,n);
   // sort_selection(stack, i);
}
// void    sort_selection(int *arr, int n)
// {
//     int i = 0;
//     quick_sort(arr, 0, n-1);
//      while(i < n)
//      {
//         printf("%d\t",arr[i]);
//         i++;}
// }

void quick_sort(int *s_arr, int first, int last)
{
    if (first < last)
    {
        int left = first, right = last, middle = s_arr[(left + right) / 2];
        do
        {
            while (s_arr[left] < middle) left++;
            while (s_arr[right] > middle) right--;
            if (left <= right)
            {
                int tmp = s_arr[left];
                s_arr[left] = s_arr[right];
                s_arr[right] = tmp;
                left++;
                right--;
            }
        } while (left <= right);
        quick_sort(s_arr, first, right);
        quick_sort(s_arr, left, last);
    }
}