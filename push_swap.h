/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 13:17:42 by caking            #+#    #+#             */
/*   Updated: 2019/08/03 23:35:30 by caking           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "ft_printf/include/ft_printf.h"
# define BUFF 5
# define MAX_FD 256

typedef struct			s_struct
{
	int					*a;
	int					*b;
	int					n;
	int					in_a;
	int					in_b;
	int					n_operation;
	int					visualization;
	unsigned int		argc;
}						t_struct;

typedef struct			s_do
{
	char				*s;
	struct s_do			*next;
}						t_do;

int						get_next_line(const int fd, char **line);
void					ft_split(t_struct *arr, char *str);
void					stack_done(t_struct *arr, char **result, int n);
void					check_dublicate(int *array, int n);
void					ft_error(int n);
void					do_sa(t_struct *arr, int f);
void					do_something(t_struct *arr, char *op);
int						need_sort(int *arr, int in_a, int n);
void					go_push_swap(t_struct *arr);
void					ft_swap_from_a(t_struct *s, t_do *op, int len, int i);
void					ft_sort_three(t_struct *s, t_do *op, int f);
void					ft_swap_two_first(t_struct *src, int f);
void					ft_put(t_struct *src, int f);
void					ft_shift_down(int *src, int n);
void					ft_shift_up(int *src, int n);
void					ft_copy_i_a(int **t, int *src, int n);
void					ft_put_a(t_struct *src);
int						find_median(int *arr, int n, int f);
int						*copy_array(int *arr, int size);
void					quicksort(int *list, int low, int high, int i);
int						what_about_med(int *arr, int n, int med, int f);
void					ft_swap_from_b(t_struct *arr, t_do *op, int len, int i);
void					ft_sort_three_with_nothing(t_struct *arr, t_do *head);
void					ft_print_stack(t_struct *src, int i, int len, int l);
int						ft_int_strlen(int num);
int						ft_atoi_ssize(char *src);
int						ft_isspace(char c);
void					vizual(t_struct *s, char *src);
void					ft_op(t_struct *s, t_do **head, char *src);
void					validate_checker(t_struct *new, int argc, char **argv);

#endif
