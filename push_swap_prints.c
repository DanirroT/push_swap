/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_prints.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:19:24 by dmota-ri          #+#    #+#             */
/*   Updated: 2026/01/08 14:19:54 by dmota-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(int *mtx, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		fprintf(stderr, " %4i", mtx[i]);
		i++;
	}
}

void	print_stacks(char *msg, t_stack stacks, t_sizes sizes)
{
	fprintf(stderr, "%10s: a", msg);
	print_stack(stacks.a, sizes.a);
	fprintf(stderr, "\t: b");
	print_stack(stacks.b, sizes.b);
	fprintf(stderr, "\n");
}

void	print_int_mtx(char *msg, int *mtx, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		fprintf(stderr, "%s %i: %i\n", msg, i + 1, mtx[i]);
		i++;
	}
	ft_putchar_fd('\n', 2);
}
