/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <caking@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 13:17:42 by caking            #+#    #+#             */
/*   Updated: 2019/07/30 15:45:16 by caking           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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


void    ft_split(t_struct *arr, char *str);
void    stack_done(t_struct *arr, char **result, int n);
void	check_dublicate(int *array, int n);
void	ft_error(int n);
