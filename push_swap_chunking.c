/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_chunking.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 22:39:46 by dmota-ri          #+#    #+#             */
/*   Updated: 2026/01/09 17:30:30 by dmota-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_rank(int value, int *order, int size)
{
	int	i;

	if (!order)
		return (-1);
	i = 0;
	while (i < size)
	{
		if (order[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

int	do_chunking_a(t_stack stack, t_sizes *sizes, int *order, int print)
{
	int			rank;
	t_mult_ind	iter;
	int			chunk_size;
	int			size_a;
	int			actions;

	iter.i = 0;
	actions = 0;
	chunk_size = ft_sqr(sizes->a, 1);
	print_stacks("Pre A", stack, *sizes);
	while (sizes->a > 0)
	{
		iter.j = 0;
		size_a = sizes->a;
		while (iter.j < (size_a) && sizes->a > 0)
		{
			rank = get_rank(stack.a[0], order, sizes->a + sizes->b);
			if (rank < iter.i + chunk_size)
				actions += do_pass_a(stack, sizes, print);
			else
				actions += do_rotate(stack.a, sizes->a, print * 'a');
			iter.j++;
		}
		iter.i += chunk_size;
	}
	print_stacks("Post A", stack, *sizes);
	return (actions);
}

int	undo_chunking_b(t_stack stack, t_sizes *sizes, char print)
{
	int	actions;

	actions = 0;
	actions += do_r_to_super(stack.b, sizes->b, 1, print * 'b');
	while (!check_sort(stack.b, sizes->b, -1))
	{
		actions += do_pass_b(stack, sizes, print);
		if (check_sort(stack.b, sizes->b, -1))
			break ;
		actions += do_r_to_super(stack.b, sizes->b, 1, print * 'b');
	}
	return (actions);
}

int	chunking_sort(t_stack stack, t_sizes sizes, int print)
{
	int		actions;
	int		*order;

	fprintf(stderr, "\tChunking Sort\n");
	print_stacks("Start", stack, sizes);
	actions = 0;
	order = get_sort_order(stack.a, sizes.a);
	actions += do_chunking_a(stack, &sizes, order, print);
	actions += undo_chunking_b(stack, &sizes, print);
	actions += do_empty_b(stack, &sizes, print);
	free(order);
	print_stacks("END", stack, sizes);
	return (actions);
}

/*
int	*get_order(int *stack, int size)
{
	int	*order;
	int	write;
	int	read;

	order = get_sort_order(stack, size);
	if (!order)
		return (NULL);
	write = 1;
	read = 1;
	while (read < size)
	{
		if (order[read] != order[write - 1])
		{
			order[write] = order[read];
			write++;
		}
		read++;
	}
	return (order);
}
*/

/*
int	undo_chunking_b(t_stack stack, t_sizes sizes, int *order, int print)
{
	int		rank;
	int		max;
	t_sizes	iter;
	int		chunk_size;
	int		actions;

	fprintf(stderr, "\t b to a\n");
	max = stack.a[src_super(stack.a, sizes.a, 1)];
	iter.a = 0;
	chunk_size = 10;
	fprintf(stderr, "\t\tpree loop\n");
	print_int_mtx("\t\tpost_loop", stack.a, sizes.a);
	while (sizes.a > 0)
	{
		iter.b = 0;
		while (iter.b < sizes.a + sizes.b && sizes.a > 0)
		{
			rank = get_rank(stack.a[0], order, max, sizes.a + sizes.b);
			if (rank >= iter.a && rank < iter.a + chunk_size)
				actions += do_pass_a(stack, &sizes, print);
			else
				actions += do_rotate(stack.a, sizes.a, print * 'a');
			print_int_mtx("\t\tpost_loop", stack.a, sizes.a);
			iter.b++;
		}
		iter.a += chunk_size;
	}
}*/