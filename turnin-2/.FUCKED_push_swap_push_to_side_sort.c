/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_push_to_side_sort.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:59:20 by dmota-ri          #+#    #+#             */
/*   Updated: 2026/01/15 14:54:46 by dmota-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_p_small(t_stack stack, t_sizes *sizes, char print)
{
	int	actions;

	actions = 0;
	if (sizes->a > 1 && stack.a[0] > stack.a[1])
		actions += do_swap(stack.a, sizes->a, print * 'a');
	while (!check_sort(stack.a, sizes->a, 1))
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

int	do_p_big(t_stack stack, t_sizes *sizes, char print)
{
	int	actions;

	actions = 0;
	if (sizes->b > 1 && stack.b[0] < stack.b[1])
		actions += do_swap(stack.b, sizes->b, print * 'b');
	while (!check_sort(stack.b, sizes->b, -1))
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

int	push_to_side(t_stack stack, t_sizes sizes, int print)
{
	int	actions;
	int	i = 0;

	actions = 0;
	//print_stacks("start", stack, sizes);
	actions += do_p_small(stack, &sizes, print);
	while (!(check_sort(stack.a, sizes.a, 1) && sizes.b == 0) && i < 20)
	{
		actions += do_p_big(stack, &sizes, print);
		actions += do_p_small(stack, &sizes, print);
	//	print_stacks("\tcore loop", stack, sizes);
		if (check_sort(stack.a, sizes.a, 1) && stack.a[0] > stack.b[0])
		{
			actions += do_empty_b(stack, &sizes, print);
			break ;
		}
		else if (stack.a[0] < stack.b[0] && stack.a[sizes.a - 1] > stack.b[0])
		{
			actions += do_revrotate(stack.a, sizes.a, print * 'a');
	//		print_stacks("\tin group", stack, sizes);
			continue ;
		}
		else if (stack.a[0] > stack.b[0] || stack.a[sizes.a - 1] < stack.b[0])
		{
			actions += do_pass_a(stack, &sizes, print);
			actions += do_swap(stack.a, sizes.a, print * 'a');
		}
	//	print_stacks("main loop", stack, sizes);
		i++;
	}
	//print_stacks("\nend", stack, sizes);
	return (actions);
}
