/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_simple_solve.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:59:20 by dmota-ri          #+#    #+#             */
/*   Updated: 2025/12/10 13:58:22 by dmota-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	simple_s_solve(t_stack stack, t_sizes sizes, int print)
{
	do_swap(stack.a, sizes.a, print * 'a');
	if (check_sort(stack.a, sizes.a, 1))
		return (1);
	return (-1);
}

int	do_r_to_super(int *stack, int size, int super, char print)
{
	int	actions;
	int	low_loc;

	actions = 0;
	low_loc = src_super(stack, size, super);
	while (low_loc)
	{
		if (low_loc > (size / 2))
		{
			actions += do_revrotate(stack, size, print);
			low_loc++;
			if (low_loc == size)
				low_loc = 0;
		}
		else
		{
			actions += do_rotate(stack, size, print);
			low_loc--;
		}
	}
	return (actions);
}

// 	if (low_loc == 1)
//		return (do_swap(stack, size, print));

int	simple_rotate_solve(t_stack stack, t_sizes sizes, int print)
{
	int	actions;

	actions = 0;
	actions += do_r_to_super(stack.a, sizes.a, -1, print * 'a');
	if (check_sort(stack.a, sizes.a, 1))
		return (actions);
	return (-1);
}
