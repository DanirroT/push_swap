/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_push_to_side_sort_stop.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:59:20 by dmota-ri          #+#    #+#             */
/*   Updated: 2025/11/28 15:46:36 by dmota-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_p_small_stop(t_stack stack, t_sizes *sizes, char print)
{
	int	actions;

	actions = 0;
	if (sizes->a > 1 && stack.a[0] > stack.a[1])
		actions += do_swap(stack.a, print * 'a');
	while (sizes->a > 1)
	{
		actions += do_pass_a(stack, sizes, print);
		if ((sizes->b > 1 && stack.b[0] < stack.b[1])
			&& (sizes->a > 1 && stack.a[0] > stack.a[1]))
			actions += do_swap_s(stack, print);
		else
		{
			if (sizes->b > 1 && stack.b[0] < stack.b[1])
				actions += do_swap(stack.b, print * 'b');
			if (sizes->a > 1 && stack.a[0] > stack.a[1])
				actions += do_swap(stack.a, print * 'a');
		}
	}
	return (actions);
}

int	do_p_big_stop(t_stack stack, t_sizes *sizes, char print)
{
	int	actions;

	actions = 0;
	while (sizes->b > 0)
	{
		actions += do_pass_b(stack, sizes, print);
		if ((sizes->b > 1 && stack.b[0] < stack.b[1])
			&& (sizes->a > 1 && stack.a[0] > stack.a[1]))
			actions += do_swap_s(stack, print);
		else
		{
			if (sizes->b > 1 && stack.b[0] < stack.b[1])
				actions += do_swap(stack.b, print * 'b');
			if (sizes->a > 1 && stack.a[0] > stack.a[1])
				actions += do_swap(stack.a, print * 'a');
		}
	}
	return (actions);
}

int	push_to_side_stop(t_stack stack, t_sizes stack_sizes, int print)
{
	int	actions;

	actions = 0;
	while (!check_sort(stack.a, stack_sizes.a, 1))
	{
		actions += do_p_small_stop(stack, &stack_sizes, print);
		actions += do_p_big_stop(stack, &stack_sizes, print);
	}
	return (actions);
}