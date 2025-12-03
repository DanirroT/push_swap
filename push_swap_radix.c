/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_radix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:53:57 by dmota-ri          #+#    #+#             */
/*   Updated: 2025/12/02 22:58:18 by dmota-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int get_max_bits(int total_size)
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

int *get_ranks(int *stack, int size)
{
	int		*ranks;
	t_sizes	iter;
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
}

int radix_sort(t_stack stack, t_sizes sizes, int print)
{
	int		actions;
	int		max_bits;
	t_sizes	iter;
	int		*ranks;

	actions = 0;
	ranks = get_ranks(stack.a, sizes.a);
	max_bits = get_max_bits(sizes.a);
	iter.a = 0;
	while (iter.a < max_bits)
	{
		iter.b = 0;
		while (iter.b < sizes.a)
		{
			if (((ranks[stack.a[0]] >> iter.a) & 1) == 0)
				actions += do_pass_a(stack, &sizes, print);
			else
				actions += do_rotate(stack.a, sizes.a, print * 'a');
			iter.b++;
		}
		actions += do_empty_b(stack, &sizes, print);
		iter.a++;
	}
	return (actions);
}
