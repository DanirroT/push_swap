/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:25:03 by dmota-ri          #+#    #+#             */
/*   Updated: 2026/01/09 15:42:37 by dmota-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"

int	ft_power(int nb, int power)
{
	if (power == 0 || nb == 1)
		return (1);
	if (power < 0)
		return (-1);
	if (power > 1)
		nb = nb * ft_power(nb, power - 1);
	return (nb);
}

int	ft_sqr(int nb, int round)
{
	int	guess;

	if (nb < 1)
		return (0);
	if (nb == 0 || nb == 1)
		return (nb);
	guess = nb / 2;
	while (!(guess < 1))
	{
		if ((guess * guess) == nb)
			return (guess);
		else if (round && (guess * guess) <= nb)
			return (guess + (round > 0));
		guess--;
	}
	return (0);
}

/*
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int	main(void)
{
	int	n;
	int	p;

	n = 2;
	p = 3;
	printf("val:\tV%i\nsqrt:\t%i\n", n, ft_sqr(n, 1));
	printf("val:\t%i^%i\nsqrt:\t%i\n", n, p, ft_power(n, p));
}

*/