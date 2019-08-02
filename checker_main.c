/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <caking@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 16:34:42 by caking            #+#    #+#             */
/*   Updated: 2019/08/02 15:33:29 by caking           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_int_strlen(int num)
{
	int				len;
	unsigned int	tmp;

	len = 1;
	if (num < 0)
	{
		len = 2;
		tmp = -num;
	}
	else
		tmp = num;
	while (tmp >= 10)
	{
		len++;
		tmp /= 10;
	}
	return (len);
}

void	ft_print_stack(t_struct *src, int i, int len, int l)
{
	ft_putstr("\n\x1b[32m__Stack_A__|__Stack_B__\x1b[0m\n");
	len = (src->in_a > src->in_b) ? src->in_a : src->in_b;
	while (++i < len)
	{
		ft_putstr("\x1b[30m\x1b[47m");
		l = (i < src->in_a) ? (11 - ft_int_strlen(src->a[i])) : 0;
		while (l--)
			ft_putstr(" ");
		(i < src->in_a) ? (ft_putnbr(src->a[i])) : 0;
		(i >= src->in_a) ? (ft_putstr("           ")) : 0;
		ft_putstr("\x1b[0m\x1b[32m|\x1b[0m\x1b[37m\x1b[40m");
		l = (i < src->in_b) ? (11 - ft_int_strlen(src->b[i])) : 0;
		while (l--)
			ft_putstr(" ");
		(i < src->in_b) ? (ft_putnbr(src->b[i])) : 0;
		(i >= src->in_b) ? (ft_putstr("           ")) : 0;
		ft_putstr("\x1b[0m\n");
	}
}

int main(int argc, char **argv)
{
    t_struct *arr;
    char     *str;

    str = NULL;
    arr =(t_struct*)malloc(sizeof(t_struct));
    arr->visualization  = 0;
    argc = 0;
    if(argc == 1 || argv[1][0] == '\0')
        ft_error(3);
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

    while (get_next_line(0, &str) > 0)
    {
        do_something(arr,str);
        (arr->visualization== 1) ? (ft_putstr("          \e[4;35m")) : 0;
		(arr->visualization == 1) ? ft_putstr(str) : 0;
		(arr->visualization == 1) ? (ft_print_stack(arr, -1, 0, 0)) : 0;
        free(str);
        arr->n_operation++;
    }
    (need_sort(arr->a, arr->in_a, arr->n) == 0)?
	(ft_printf("\033[0;31mKO\n\e[0m")) : (ft_printf("\033[0;32mOK\n\e[0m"));
    return(0);
}