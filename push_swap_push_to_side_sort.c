/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_push_to_side_sort.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:59:20 by dmota-ri          #+#    #+#             */
/*   Updated: 2025/11/20 14:04:49 by dmota-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_p_small(t_stack stack, t_sizes *sizes, char print)
{
	int	actions;

	printf("\t a to b\n");
	actions = 0;
	while (sizes->a > 1)
	{
		if (sizes->a > 1 && stack.a[0] > stack.a[1])
			actions += do_swap(stack.a, print * 'a');
		actions += do_pass_a(stack, sizes, print);
		if (sizes->b > 1 && stack.b[0] > stack.b[1])
			actions += do_swap(stack.b, print * 'b');
	}
	return (actions);
}

int	do_p_big(t_stack stack, t_sizes *sizes, char print)
{
	int	actions;

	printf("\t b to a\n");
	actions = 0;
	while (sizes->b > 0)
	{
		if (sizes->b > 1 && stack.b[0] < stack.b[1])
			actions += do_swap(stack.b, print * 'b');
		actions += do_pass_b(stack, sizes, print);
		if (sizes->a > 1 && stack.a[0] > stack.a[1])
			actions += do_swap(stack.a, print * 'a');
	}
	return (actions);
}

int	push_to_side(t_stack stack, t_sizes stack_sizes, int *sorted, int print)
{
	int	actions;

	printf("Push to Side\n");
	actions = 0;
	while (ft_memcmp(stack.a, sorted, stack_sizes.a * sizeof(int)))
	{
		printf("Attempt sort\n");
		actions += do_p_small(stack, &stack_sizes, print);
		print_int_mtx("\tpost_a.a", stack.a, stack_sizes.a);
		print_int_mtx("\tpost_a.b", stack.b, stack_sizes.b);
		actions += do_p_big(stack, &stack_sizes, print);
		print_int_mtx("\tpost_b.a", stack.a, stack_sizes.a);
		print_int_mtx("\tpost_b.b", stack.b, stack_sizes.b);
	}
	return (actions);
}
