/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:23:32 by dmota-ri          #+#    #+#             */
/*   Updated: 2026/01/24 18:40:53 by dmota-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "libft/ft_printf.h"
# include <stdio.h>
# include <limits.h>

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

typedef struct s_mult_ind
{
	int	i;
	int	j;
	int	k;
}		t_mult_ind;

// main

int		ft_out(t_stack *stack, int *input, char **handle_temp, int code);
void	*assign_funct(void);

int		main(int argc, char *argv[]);

// utils
int	check_do_atoi(char **arg, int rep, int *input);
void	one_arg_to_stack(const char *nptr, t_stack *stack, int *input,
			int size);
int		check_sort(int *stack, int size, int order);
int		src_super(int *stack, int size, int superlative);
int		check_dups(int *stack, int len);
int		ft_num_count(char *args[]);

// Operations
int		do_pass_a(t_stack stack, t_sizes *size, char print);
int		do_pass_b(t_stack stack, t_sizes *size, char print);

int		do_swap(int *stack, int size, char print);
int		do_swap_s(t_stack stack, t_sizes sizes, char print);
int		do_rotate(int *stack, int stack_size, char print);
int		do_rotate_r(t_stack stack, t_sizes stack_sizes, char print);

int		do_revrotate(int *stack, int stack_size, char print);
int		do_revrotate_r(t_stack stack, t_sizes stack_sizes, char print);

// Simple Solves
int		simple_s_solve(t_stack stack, t_sizes sizes, int print);
int		solve_for_three(t_stack stack, t_sizes sizes, int print);
int		do_r_to_super(int *stack, int size, int super, char print);
int		simple_rotate_solve(t_stack stack, t_sizes sizes, int print);

// Push to side
int		do_p_small(t_stack stack, t_sizes *sizes, char print);
int		do_p_big(t_stack stack, t_sizes *sizes, char print);
int		push_to_side(t_stack stack, t_sizes stack_sizes, int print);

// Push to side Stop
int		do_p_small_empty(t_stack stack, t_sizes *sizes, char print);
int		do_p_big_empty(t_stack stack, t_sizes *sizes, char print);
int		push_to_side_empty(t_stack stack, t_sizes stack_sizes, int print);

// Rotate to side

int		do_rp_small(t_stack stack, t_sizes *sizes, char print);
int		do_empty_b(t_stack stack, t_sizes *sizes, char print);
int		rotate_to_side(t_stack stack, t_sizes stack_sizes, int print);

// radix Sort (500) 
int		*get_sort_order(int *to_sort, int len);
int		get_max_bits(int total_size);
int		radix_sort(t_stack stack, t_sizes sizes, int print);

// Chunking Sort (100)
int		get_rank(int value, int *order, int size);
int		do_chunking_a(t_stack stack, t_sizes *sizes, int *order, int print);
int		undo_chunking_b(t_stack stack, t_sizes *sizes, char print);
int		chunking_sort(t_stack stack, t_sizes sizes, int print);

// prints
void	print_stack(int *mtx, int len);
void	print_stacks(char *msg, t_stack stacks, t_sizes sizes);
void	print_int_mtx(char *msg, int *mtx, int len);

#endif
