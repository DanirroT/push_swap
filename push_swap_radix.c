/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_radix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:53:57 by dmota-ri          #+#    #+#             */
/*   Updated: 2026/01/08 17:04:20 by dmota-ri         ###   ########.fr       */
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

int	radix_sort(t_stack stack, t_sizes sizes, int print)
{
	int			actions;
	int			size_a;
	t_mult_ind	iter;
	int			*order;

	fprintf(stderr, "\tRadix Sort\n");
	actions = 0;
	order = get_sort_order(stack.a, sizes.a);
	if (!order)
		return (-1);
	iter.i = 0;
	print_stacks("Start", stack, sizes);
	while (iter.i < get_max_bits(sizes.a + sizes.b))
	{
		iter.j = 0;
		size_a = sizes.a;
		while (iter.j < (size_a))
		{
			fprintf(stderr, "\tpreLogic lookup: %i Rank: %i\n",
				stack.a[0], get_rank(stack.a[0], order, sizes.a + sizes.b));
			if (((get_rank(stack.a[0], order, sizes.a + sizes.b)
						>> iter.i) & 1) == 0)
				actions += do_pass_a(stack, &sizes, print);
			else
				actions += do_rotate(stack.a, sizes.a, print * 'a');
			iter.j++;
			print_stacks("post logic", stack, sizes);
		}
		print_stacks("preEmpty", stack, sizes);
		actions += do_empty_b(stack, &sizes, print);
		iter.i++;
	}
	free(order);
	print_stacks("END", stack, sizes);
	return (actions);
}
