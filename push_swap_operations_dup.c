/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_dup.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:52:35 by dmota-ri          #+#    #+#             */
/*   Updated: 2025/11/25 15:41:15 by dmota-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_swap_s(t_stack stack, char print)
{
	do_swap(stack.a, 0);
	do_swap(stack.b, 0);
	if (print)
		ft_putstr_fd("ss\n", 1);
	return (1);
}

int	do_rotate_r(t_stack stack, t_sizes sizes, char print)
{
	do_rotate(stack.a, sizes.a, 0);
	do_rotate(stack.b, sizes.b, 0);
	if (print)
		ft_putstr_fd("rr\n", 1);
	return (1);
}

int	do_revrotate_r(t_stack stack, t_sizes sizes, char print)
{
	do_revrotate(stack.a, sizes.a, 0);
	do_revrotate(stack.b, sizes.b, 0);
	if (print)
		ft_putstr_fd("rrr\n", 1);
	return (1);
}
