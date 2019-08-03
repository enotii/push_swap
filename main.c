/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 13:16:53 by caking            #+#    #+#             */
/*   Updated: 2019/08/03 21:32:31 by caking           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
    t_struct    *arr;

	(argc == 1) ? (exit(-1)) : 0;
	(argv[1][0] == '\0') ? (ft_error(2)) : 0;
    arr = (t_struct*)malloc(sizeof(t_struct));
    arr->visualization = 0;
    if(ft_strcmp(argv[1],"-v") == 0)
        arr->visualization = 1;
    if(ft_strcmp(argv[1],"-c") == 0)
        arr->visualization = 2;
    if(argc == 2)
        ft_split(arr,argv[1]);
    else if(argc > 2)
    {
        arr->argc = 1;
        stack_done(arr,argv,argc);
    }
    check_dublicate(arr->a,arr->n);
    if (need_sort(arr->a, arr->in_a, arr->n))
		return (0);
    if(arr->n == 2)
    {
        do_something(arr, "sa");
        ft_putstr("sa\n");
        exit(0);
    }
   else if(arr->n > 2)
       go_push_swap(arr);
    free(arr->a);
    free(arr);
    return 0;
}
