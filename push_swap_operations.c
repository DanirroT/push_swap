/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:52:35 by dmota-ri          #+#    #+#             */
/*   Updated: 2025/12/10 17:04:21 by dmota-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_pass_a(t_stack stack, t_sizes *size, char print)
{
	int	i;

	if (size->a == 0)
		return (0);
	i = size->b;
	while (i)
	{
		stack.b[i] = stack.b[i - 1];
		i--;
	}
	stack.b[0] = stack.a[0];
	while (i < size->a - 1)
	{
		stack.a[i] = stack.a[i + 1];
		i++;
	}
	stack.a[size->a - 1] = 0;
	size->b++;
	size->a--;
	if (print)
		ft_putstr_fd("pb\n", 1);
	return (1);
}

int	do_pass_b(t_stack stack, t_sizes *size, char print)
{
	int	i;

	if (size->b == 0)
		return (0);
	i = size->a;
	while (i)
	{
		stack.a[i] = stack.a[i - 1];
		i--;
	}
	stack.a[0] = stack.b[0];
	while (i < size->b - 1)
	{
		stack.b[i] = stack.b[i + 1];
		i++;
	}
	stack.b[size->b - 1] = 0;
	size->a++;
	size->b--;
	if (print)
		ft_putstr_fd("pa\n", 1);
	return (1);
}

int	do_swap(int *stack, int size, char print)
{
	int	temp;

	if (size < 2)
		return (0);
	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
	if (print)
		ft_printf("s%c\n", print);
	return (1);
}

int	do_rotate(int *stack, int stack_size, char print)
{
	int	temp;
	int	i;

	if (stack_size <= 1)
		return (0);
	i = 0;
	temp = stack[0];
	while (i < stack_size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[stack_size - 1] = temp;
	if (print)
		ft_printf("r%c\n", print);
	return (1);
}

int	do_revrotate(int *stack, int stack_size, char print)
{
	int	temp;
	int	i;

	if (stack_size <= 1)
		return (0);
	temp = stack[stack_size - 1];
	i = stack_size - 1;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = temp;
	if (print)
		ft_printf("rr%c\n", print);
	return (1);
}
