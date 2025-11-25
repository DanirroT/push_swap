/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:24:35 by dmota-ri          #+#    #+#             */
/*   Updated: 2025/11/25 17:59:19 by dmota-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isatoi(const char *str)
{
	int				i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (!(str[i] == '+' || str[i] == '-' || str[i] >= ' '
				|| (str[i] >= 9 && str[i] <= 13)
				|| (str[i] >= '0' && str[i] <= '9')))
			return (0);
		i++;
	}
	return (1);
}

int	check_sort(int *stack, int size, int order)
{
	int	i;

	i = 0;
	while (i < size -1)
	{
		if (stack[i] > stack[i + 1] && order == 1)
			return (0);
		if (stack[i] < stack[i + 1] && order == -1)
			return (0);
		i++;
	}
	return (1);
}

int	src_super(int *stack, int size, int superlative)
{
	int	i;
	int	loc;

	loc = 0;
	i = 0;
	while (i < size -1)
	{
		if (stack[loc] > stack[i] && superlative == 1)
			loc = i;
		if (stack[loc] < stack[i] && superlative == -1)
			loc = i;
		i++;
	}
	return (loc);
}
