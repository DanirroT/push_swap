/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate_to_side.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:49:40 by dmota-ri          #+#    #+#             */
/*   Updated: 2025/12/10 19:05:05 by dmota-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_rp_small(t_stack stack, t_sizes *sizes, char print)
{
	int	actions;

	actions = 0;
	actions += do_r_to_super(stack.a, sizes->a, -1, print * 'a');
	while (!check_sort(stack.a, sizes->a, 1))
	{
		actions += do_pass_a(stack, sizes, print);
		if (check_sort(stack.a, sizes->a, 1))
			break ;
		actions += do_r_to_super(stack.a, sizes->a, -1, print * 'a');
	}
	return (actions);
}

int	do_empty_b(t_stack stack, t_sizes *sizes, char print)
{
	int	actions;

	actions = 0;
	while (sizes->b > 0)
		actions += do_pass_b(stack, sizes, print);
	return (actions);
}

int	rotate_to_side(t_stack stack, t_sizes stack_sizes, int print)
{
	int	actions;

	actions = 0;
	while (!check_sort(stack.a, stack_sizes.a, 1))
	{
		actions += do_rp_small(stack, &stack_sizes, print);
		actions += do_empty_b(stack, &stack_sizes, print);
	}
	return (actions);
}
