/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <caking@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 16:03:17 by caking            #+#    #+#             */
/*   Updated: 2019/07/29 18:35:10 by caking           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_swap(int *arr, int n)
{
    int med;
    int i;
    int *b;

    med = 0;
   //--------------медиана--------------//
    if(n % 2 == 0)
    med = (arr[(n/2) + 1] + arr[(n/2)-1]) / 2; 
    else if(n % 2 != 0)
    med = arr[n/2];
    //---------------------------------//
    i = 0;
    while(i < n)
    {
        printf("%d\t",arr[i]);
        i++;
    }
   // i = 0;
    b =(int*)malloc(n * sizeof(int));
    // while(i < n)
    // {
    //     if()
    // }
}

void swap(int *arr,int n)
{
    int tmp;
    
    tmp = 0;
    if(arr[n] && arr[n - 1])
    {     
    tmp = arr[n];
    arr[n] = arr[n - 1];
    arr[n - 1] = arr[n];
    }
}

void push(int *a, int *b, int na, int nb)
{
    int tmp;

    tmp = 0;
    if(b)
    {
        tmp = a[na];
        a[na] = b[nb];
    }
}

void    rotate(int *arr, int n)
{
    int tmp;
    int i;

    tmp = arr[0];
    i = 1;
    while(i < n)
    {
        arr[i - 1] = arr[i];
        i++;
    }
    arr[n] = tmp;
}

void rra(int *arr, int n)
{
    int tmp;
    int i;

    tmp = arr[n];
    i = 0;
    while(i < n)
    {
        arr[i + 1] = arr[i];
        i++;
    }
    arr[0] = tmp;
}

int main(int argc, char *argv[])
{
    if (argv[1] && argc == 2)
    {
        ft_split(argv[1]);
    }
    else
    return 0;
}
