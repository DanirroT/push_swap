/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_simple_solve.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:59:20 by dmota-ri          #+#    #+#             */
/*   Updated: 2025/12/03 11:47:59 by dmota-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	simple_s_solve(t_stack stack, t_sizes sizes, int print)
{
	do_swap(stack.a, print * 'a');
	if (check_sort(stack.a, sizes.a, 1))
		return (1);
	return (-1);
}

int	simple_r_solve(t_stack stack, t_sizes sizes, int print)
{
	int	actions;

	actions = 0;
	while (!check_sort(stack.a, sizes.a, 1) && actions <= sizes.a + 1 / 2)
		actions += do_revrotate(stack.a, sizes.a, print * 'a');
	if (check_sort(stack.a, sizes.a, 1))
		return (actions);
	return (-1);
}

int	simple_rr_solve(t_stack stack, t_sizes sizes, int print)
{
	int	actions;

	actions = 0;
	while (!check_sort(stack.a, sizes.a, 1) && actions <= sizes.a + 1 / 2)
		actions += do_rotate(stack.a, sizes.a, print * 'a');
	if (check_sort(stack.a, sizes.a, 1))
		return (actions);
	return (-1);
}
