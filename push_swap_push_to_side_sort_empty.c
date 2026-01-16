/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_push_to_side_sort_empty.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:59:20 by dmota-ri          #+#    #+#             */
/*   Updated: 2026/01/06 19:00:23 by dmota-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_p_small_empty(t_stack stack, t_sizes *sizes, char print)
{
	int	actions;

	actions = 0;
	if (sizes->a > 1 && stack.a[0] > stack.a[1])
		actions += do_swap(stack.a, sizes->a, print * 'a');
	while (sizes->a > 1)
	{
		actions += do_pass_a(stack, sizes, print);
		if ((sizes->b > 1 && stack.b[0] < stack.b[1])
			&& (sizes->a > 1 && stack.a[0] > stack.a[1]))
			actions += do_swap_s(stack, *sizes, print);
		else
		{
			if (sizes->b > 1 && stack.b[0] < stack.b[1])
				actions += do_swap(stack.b, sizes->b, print * 'b');
			if (sizes->a > 1 && stack.a[0] > stack.a[1])
				actions += do_swap(stack.a, sizes->a, print * 'a');
		}
	}
	return (actions);
}

int	do_p_big_empty(t_stack stack, t_sizes *sizes, char print)
{
	int	actions;

	actions = 0;
	while (sizes->b > 0)
	{
		actions += do_pass_b(stack, sizes, print);
		if ((sizes->b > 1 && stack.b[0] < stack.b[1])
			&& (sizes->a > 1 && stack.a[0] > stack.a[1]))
			actions += do_swap_s(stack, *sizes, print);
		else
		{
			if (sizes->b > 1 && stack.b[0] < stack.b[1])
				actions += do_swap(stack.b, sizes->b, print * 'b');
			if (sizes->a > 1 && stack.a[0] > stack.a[1])
				actions += do_swap(stack.a, sizes->a, print * 'a');
		}
	}
	return (actions);
}

int	push_to_side_empty(t_stack stack, t_sizes stack_sizes, int print)
{
	int	actions;

	actions = 0;
	while (!check_sort(stack.a, stack_sizes.a, 1))
	{
		actions += do_p_small_empty(stack, &stack_sizes, print);
		actions += do_p_big_empty(stack, &stack_sizes, print);
	}
	return (actions);
}
