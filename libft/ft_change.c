/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:40:20 by dmota-ri          #+#    #+#             */
/*   Updated: 2025/10/31 13:29:37 by dmota-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	neg;
	int	num;

	if (!nptr)
		return (0);
	i = 0;
	num = 0;
	neg = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + (nptr[i] - '0');
		i++;
	}
	return (neg * num);
}
//	The  atoi() function converts the initial portion of the string pointed
//		to by nptr to int.  The behavior is the same as:
//			strtol(nptr, NULL, 10);
//		except that atoi() does not detect errors.

static size_t	ft_numlen(long int n)
{
	int	len;

	if (!n)
		return (1);
	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long int	nb;
	size_t		len;
	char		*result;

	nb = n;
	len = ft_numlen(nb);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	if (nb == 0)
		result[0] = '0';
	if (nb < 0)
	{
		result[0] = '-';
		nb = -nb;
	}
	result[len] = 0;
	while (nb > 0)
	{
		len--;
		result[len] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (result);
}
//	Allocates memory (using malloc(3)) and returns a string representing
//		the integer received as an argument. Negative numbers must be handled.

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}
//	These functions convert lowercase letters to uppercase.

//DONE

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}
//	These functions convert uppercase letters to lowercase.

//DONE
/*

#ifndef NO_MAIN

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	//int	num_i = -2147483648;

	//printf("\nitoa: %i\n", num_i);

	//char *ft = ft_itoa(num_i);

//	printf("\ntotal: %s\n", ft);
//	printf("1: %c\n", ft[0]);
//	printf("2: %c\n", ft[1]);
//	printf("3: %c\n", ft[2]);
//	printf("4: %c\n", ft[3]);
//	printf("5: %c\n", ft[4]);
//	printf("6: %i\n", ft[5]);

//	free(ft);

	printf("\natoi\n");

//	printf("-:\tft:\t%i\t%i\n", ft_atoi(""), atoi(""));
//	printf("1:\tft:\t%i\t%i\n", ft_atoi("   1"), atoi("   1"));
//	printf("0:\tft:\t%i\t%i\n", ft_atoi("0"), atoi("0"));
//	printf("a1:\tft:\t%i\t%i\n", ft_atoi("a1"), atoi("a1"));
//	printf("--1:\tft:\t%i\t%i\n", ft_atoi("--1"), atoi("--1"));
//	printf("++1:\tft:\t%i\t%i\n", ft_atoi("++1"), atoi("++1"));
//	printf("-1:\tft:\t%i\t%i\n", ft_atoi("-1"), atoi("-1"));
//	printf("+1:\tft:\t%i\t%i\n", ft_atoi("+1"), atoi("+1"));
//	printf("+101:\tft:\t%i\t%i\n", ft_atoi("+101"), atoi("+101"));
//	printf("42lyon:\tft:\t%i\t%i\n", ft_atoi("42lyon"), atoi("42lyon"));
//	printf("MIN:\tft:\t%i\t%i\n", ft_atoi("-2147483648"), atoi("-2147483648"));
//	printf("MAX:\tft:\t%i\t%i\n", ft_atoi("2147483647"), atoi("2147483647"));
//	printf("-+42:\tft:\t%i\t%i\n", ft_atoi("-+42"), atoi("-+42"));
//	printf("Empty:\tft:\t%i\t%i\n", ft_atoi(""), atoi(""));
	int n1 = ft_atoi("");
	int n2 = atoi("");
	printf("NULL:\tft:\t%i\t%i\n", n1, n2);

//	char c3 = 'a';
//	char c4 = 'A';

//	printf("\ntoupper: %c %c\n", ft_toupper(c3), toupper(c3));
//	printf("\ntolower: %c %c\n", ft_tolower(c4), tolower(c4));
}

#endif
*/