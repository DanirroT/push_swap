/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:23:32 by dmota-ri          #+#    #+#             */
/*   Updated: 2025/11/26 12:57:32 by dmota-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "libft/ft_printf.h"
# include <stdio.h>

typedef struct s_stack
{
	int	*a;
	int	*b;
}		t_stack;

typedef struct s_sizes
{
	int	a;
	int	b;
}		t_sizes;

// utils
int		ft_isatoi(const char *str);
int		check_sort(int *stack, int size, int order);
int		src_super(int *stack, int size, int superlative);

void	print_int_mtx(char *msg, int *mtx, int len);

// Operations
int		do_pass_a(t_stack stack, t_sizes *size, char print);
int		do_pass_b(t_stack stack, t_sizes *size, char print);

int		do_swap(int *stack, char print);
int		do_swap_s(t_stack stack, char print);
int		do_rotate(int *stack, int stack_size, char print);
int		do_rotate_r(t_stack stack, t_sizes stack_sizes, char print);

int		do_revrotate(int *stack, int stack_size, char print);
int		do_revrotate_r(t_stack stack, t_sizes stack_sizes, char print);

// Push to side
int		do_p_small(t_stack stack, t_sizes *sizes, char print);
int		do_p_big(t_stack stack, t_sizes *sizes, char print);
int		push_to_side(t_stack stack, t_sizes stack_sizes, int print);

// Rotate to side
int		do_r_to_small(t_stack stack, t_sizes *sizes, char print);
int		do_rp_small(t_stack stack, t_sizes *sizes, char print);
int		do_empty_b(t_stack stack, t_sizes *sizes, char print);
int		rotate_to_side(t_stack stack, t_sizes stack_sizes, int print);

// Simple Solves
int simple_s_solve(t_stack stack, t_sizes sizes, int print);
int simple_r_solve(t_stack stack, t_sizes sizes, int print);
int simple_rr_solve(t_stack stack, t_sizes sizes, int print);

#endif
