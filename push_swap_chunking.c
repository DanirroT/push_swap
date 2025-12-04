/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_chunking.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 22:39:46 by dmota-ri          #+#    #+#             */
/*   Updated: 2025/12/04 14:11:25 by dmota-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_sort_order(int *to_sort, int len)
{
	int		j;
	int		k;
	int		temp;
	int		*sorted;

	sorted = ft_calloc(sizeof(int), len);
	ft_memcpy(sorted, to_sort, sizeof(int) * len);
	k = 0;
	while (k < len - 1)
	{
		j = k + 1;
		while (j < len)
		{
			if (sorted[k] > sorted[j])
			{
				temp = sorted[k];
				sorted[k] = sorted[j];
				sorted[j] = temp;
			}
			j++;
		}
		k++;
	}
	return (sorted);
}

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

int	get_rank(int value, int *order, int max, int size)
{
	int	i;

	if (!order)
		return (-1);
	i = 0;
	while (order[i] <= max && i < size)
	{
		if (order[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

int	do_chunking_a(t_stack stack, t_sizes sizes, int *order, int print)
{
	int		rank;
	int		max;
	t_sizes	iter;
	int		chunk_size;
	int		actions;

	max = stack.a[src_super(stack.a, sizes.a, 1)];
	iter.a = 0;
	chunk_size = 10;
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
			iter.b++;
		}
		iter.a += chunk_size;
	}
}

int	chunking_sort(t_stack stack, t_sizes sizes, int print)
{
	int		actions;
	int		*order;

	actions = 0;
	order = get_order(stack.a, sizes.a);
	actions += do_chunking_a(stack, sizes, order, print);
	actions += undo_chunking_b(stack, sizes, order, print);
	free(order);
	return (actions);
}

/*int	chunking_sort(t_stack stack, t_sizes sizes, int print)
{
	int		actions;
	int		*ranks;
	int		chunk_size;
	t_sizes	limit;

	actions = 0;
	chunk_size = 10; // ~ sqr(sizes.a)
	ranks = get_ranks(stack.a, sizes.a);
	limit.b = chunk_size;
	while (sizes.a > 0)
	{
		limit.a = sizes.a;
		while (limit.a > 0 && sizes.a > 0)
		{
			if (get_rank(stack.a[0], ranks, sizes.a) >= 0)
			{
				actions += do_pass_a(stack, &sizes, print);
				if (limit.b < sizes.a && sizes.b > 1) 
					actions += do_rotate(stack.b, sizes.b, print * 'b');
			}
			else
				actions += do_rotate(stack.a, sizes.a, print * 'a');
			limit.a--;
		}
		limit.b += chunk_size;
	}
	actions += do_empty_b(stack, &sizes, print);
	free(ranks);
	return (actions);
}*/
