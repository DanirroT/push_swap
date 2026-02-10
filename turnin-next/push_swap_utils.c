/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:24:35 by dmota-ri          #+#    #+#             */
/*   Updated: 2026/01/24 19:01:41 by dmota-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_do_atoi(char **arg, int rep, int *input)
{
	int			neg;
	int			i;
	long long	num;

	num = 0;
	i = 0;
	neg = 1;
	if (arg[rep][i] == '-' || arg[rep][i] == '+')
		if (arg[rep][i++] == '-')
			neg = -1;
	if (!ft_isdigit(arg[rep][i]))
		ft_out(NULL, input, arg, 2);
	while (ft_isdigit(arg[rep][i]))
	{
		if ((num * 10 + (arg[rep][i] - '0')) * neg > INT_MAX
			|| (num * 10 + (arg[rep][i] - '0')) * neg < INT_MIN)
			ft_out(NULL, input, arg, 1);
		num = num * 10 + (arg[rep][i] - '0');
		i++;
	}
	if (arg[rep][i] != '\0')
		ft_out(NULL, input, arg, 2);
	return (neg * num);
}

/* 	else if (argc == 2)
		stack_sizes.a = ft_num_count(argv[1]);
	else
		stack_sizes.a = argc - 1; */

int	ft_num_count(char *args[])
{
	int			num_count;
	int			in_num;
	t_mult_ind	ind;

	num_count = 0;
	ind.i = -1;
	while (args[++ind.i])
	{
		in_num = 0;
		ind.j = -1;
		while (args[ind.i][++ind.j])
		{
			if (!ft_isitoa(args[ind.i][ind.j]))
				ft_out(NULL, NULL, NULL, -1);
			if (!ft_isspace(args[ind.i][ind.j]) && in_num == 0)
			{
				in_num = 1;
				num_count++;
			}
			if (ft_isspace(args[ind.i][ind.j]))
				in_num = 0;
		}
	}
	return (num_count);
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
	i = 1;
	while (i < size)
	{
		if (stack[loc] < stack[i] && superlative == 1)
			loc = i;
		else if (stack[loc] > stack[i] && superlative == -1)
			loc = i;
		i++;
	}
	return (loc);
}

int	check_dups(int *stack, int len)
{
	int		j;
	int		k;

	k = 0;
	while (k < len - 1)
	{
		j = k + 1;
		while (j < len)
		{
			if (stack[k] == stack[j])
				return (1);
			j++;
		}
		k++;
	}
	return (0);
}

//void	one_arg_to_stack(const char *nptr, int *input, int size, int neg)
//{
//	long long	num;
//	int			i;

//	i = -1;
//	while (*nptr != '\0' && ++i < size)
//	{
//		num = 0;
//		neg = 1;
//		while (ft_isspace(*nptr))
//			nptr++;
//		if (*nptr == '-' || *nptr == '+')
//			if (*nptr++ == '-')
//				neg = -1;
//		if (!ft_isdigit(*nptr))
//			return (NULL);
//		while (ft_isdigit(*nptr))
//		{
//			if ((num * 10 + (*nptr - '0')) * neg > INT_MAX
//				|| (num * 10 + (*nptr - '0')) * neg < INT_MIN)
//				return (NULL);
//			num = num * 10 + (*nptr - '0');
//			nptr++;
//		}
//		input[i] = neg * num;
//	}
//}