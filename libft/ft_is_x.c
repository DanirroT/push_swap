/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:25:03 by dmota-ri          #+#    #+#             */
/*   Updated: 2025/10/26 15:03:52 by dmota-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
//	checks  for  an  alphabetic  character; in the standard "C" locale,
//		it is equivalent to (isupper(c) || islower(c)).  In some locales,
//		there may be  additional  characters  for which isalpha() is
//		true—letters which are neither uppercase nor lowercase.

//DONE

int	ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9'));
}
//	checks for a digit (0 through 9).

//DONE

int	ft_isalnum(int c)
{
	return (ft_isdigit(c) || ft_isalpha(c));
}
//	checks for an alphanumeric character; it is equivalent to
//		(isalpha(c) || isdigit(c)).

//DONE

int	ft_isprint(int c)
{
	return ((c >= ' ' && c <= '~'));
}
//	checks for any printable character including space.

//DONE

int	ft_isascii(int c)
{
	return ((c >= 0 && c <= 127));
}
//	checks whether c is a 7-bit unsigned char value that fits into the ASCII
//		character set.

//DONE

/*
#ifndef NO_MAIN

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	char	c;

	c = ';';
//	printf("char:\t\t'%c' ou %i\n", c, c);
//	printf("isalpha:\t%i, %i\n", ft_isalpha(c), isalpha(c));
//	printf("isdigit:\t%i, %i\n", ft_isdigit(c), isdigit(c));
//	printf("isalnum:\t%i, %i\n", ft_isalnum(c), isalnum(c));
//	printf("isprint:\t%i, %i\n", ft_isprint(c), isprint(c));
//	printf("isascii:\t%i, %i\n", ft_isascii(c), isascii(c));
}

#endif
*/