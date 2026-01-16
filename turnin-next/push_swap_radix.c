/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_radix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:53:57 by dmota-ri          #+#    #+#             */
/*   Updated: 2026/01/15 13:29:28 by dmota-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(int total_size)
{
	int	max_value;
	int	max_bits;

	max_value = total_size - 1;
	if (max_value < 0)
		return (0);
	max_bits = 0;
	while (max_value > 0)
	{
		max_value = max_value >> 1;
		max_bits++;
	}
	return (max_bits);
}

int	*get_sort_order(int *to_sort, int len)
{
	int		j;
	int		k;
	int		temp;
	int		*sorted;

	sorted = malloc(sizeof(int) * len);
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

/*
int	*get_ranks(int *stack, int size)
{
	int		*ranks;
	t_mult_ind	iter;
	int		rank_count;

	
	ranks = (int *)malloc(sizeof(int) * size);
	if (!ranks)
		return (NULL);
	iter.a = 0;
	while (iter.a < size)
	{
		rank_count = 0;
		iter.b = 0;
		while (iter.b < size)
		{
			if (stack[iter.b] < stack[iter.a])
				rank_count++;
			iter.b++;
		}
		ranks[iter.a] = rank_count;
		iter.a++;
	}
	return (ranks);
}*/

int	radix_sort(t_stack stack, t_sizes sz, int print)
{
	int			actions;
	int			size_a;
	t_mult_ind	iter;
	int			*order;

	actions = 0;
	order = get_sort_order(stack.a, sz.a);
	if (!order)
		return (-1);
	iter.i = -1;
	while (++iter.i < get_max_bits(sz.a + sz.b))
	{
		iter.j = -1;
		size_a = sz.a;
		while (++iter.j < (size_a))
		{
			if (((get_rank(stack.a[0], order, sz.a + sz.b) >> iter.i) & 1) == 0)
				actions += do_pass_a(stack, &sz, print);
			else
				actions += do_rotate(stack.a, sz.a, print * 'a');
		}
		actions += do_empty_b(stack, &sz, print);
	}
	free(order);
	return (actions);
}
