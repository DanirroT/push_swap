/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_dup.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:52:35 by dmota-ri          #+#    #+#             */
/*   Updated: 2025/11/19 15:07:24 by dmota-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_swap_s(t_stack stack, char print)
{
	do_swap(stack.a, 0);
	do_swap(stack.b, 0);
	if (print)
		ft_printf("ss\n");
	return (1);
}

int	do_rotate_r(t_stack stack, t_sizes sizes, char print)
{
	do_rotate(stack.a, sizes.a, 0);
	do_rotate(stack.b, sizes.b, 0);
	if (print)
		ft_printf("rr\n");
	return (1);
}

int	do_revrotate_r(t_stack stack, t_sizes sizes, char print)
{
	do_revrotate(stack.a, sizes.a, 0);
	do_revrotate(stack.b, sizes.b, 0);
	if (print)
		ft_printf("rrr\n");
	return (1);
}
