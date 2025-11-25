/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:23:32 by dmota-ri          #+#    #+#             */
/*   Updated: 2025/11/20 14:20:30 by dmota-ri         ###   ########.fr       */
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

typedef struct s_order
{
	int	*input;
	int	*output;
}		t_order;

// utils
int	ft_isatoi(const char *str);

// Operations
int	do_pass_a(t_stack stack, t_sizes *size, char print);
int	do_pass_b(t_stack stack, t_sizes *size, char print);

int	do_swap(int *stack, char print);
int	do_swap_s(t_stack stack, char print);

int	do_rotate(int *stack, int stack_size, char print);
int	do_rotate_r(t_stack stack, t_sizes stack_sizes, char print);

int	do_revrotate(int *stack, int stack_size, char print);
int	do_revrotate_r(t_stack stack, t_sizes stack_sizes, char print);

// Sorters
int	push_to_side(t_stack stack, t_sizes stack_sizes,
		int *output_order, int print);

// Push to side
int	do_p_small(t_stack stack, t_sizes *sizes, char print);
int	do_p_big(t_stack stack, t_sizes *sizes, char print);
int	push_to_side(t_stack stack, t_sizes stack_sizes, int *sorted, int print);
#endif
