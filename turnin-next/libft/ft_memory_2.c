/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:12:48 by dmota-ri          #+#    #+#             */
/*   Updated: 2025/11/25 15:36:24 by dmota-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;

	if (!n || !s)
		return (NULL);
	i = 0;
	s1 = (unsigned char *)s;
	while (!(i >= n))
	{
		s1[i] = (unsigned char)c;
		i++;
	}
	return ((void *)s1);
}
//	The memset() function fills the first n bytes of the memory area
//		pointed to by s with the constant byte c. : The memset()
//		function returns a pointer to the memory area s.

// DONE

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*res;
	size_t			i;
	size_t			len;

	if (!nmemb || !size)
		return (malloc(0));
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	len = ((nmemb) * (size));
	res = malloc(sizeof(unsigned char) * len);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = 0;
		i++;
	}
	return (res);
}

//	The calloc() function allocates memory for an array of nmemb elements of
//		size bytes each and returns a pointer to the allocated memory.
//		The memory is set to zero. If nmemb or size is 0,
//		then calloc() returns a unique pointer value that
//		can later be successfully passed to free().

// Translation: create a nmemb(elements) x size(len) matrix. set all to 0
/*
#ifndef NO_MAIN


# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int	main(void)
{
	char	*s7f;
	char	*s7o;

//	char	s6f[] = "12345";
//	char	s6o[] = "12345";
//	ft_memset(s6f, 'a', 3);
//	memset(s6o, 'a', 3);
//	printf("\nmemset\tft: %c%c%c%c%c ; og: %c%c%c%c%c\n", s6f[0], s6f[1],
//		s6f[2], s6f[3], s6f[4], s6o[0], s6o[1], s6o[2], s6o[3], s6o[4]);
	s7o = calloc(2, 2);
	printf("calloc\nog: %i\n", s7o[0]);
	printf("calloc\nog: %i\n", s7o[1]);
	printf("calloc\nog: %i\n", s7o[2]);
	s7f = ft_calloc(2, 2);
	printf("calloc\nft: %i\n", s7f[0]);
	printf("\nft: %i ; og: %i\n", s7f[1], s7o[1]);
	printf("\nft: %i ; og: %i\n", s7f[2], s7o[2]);
	free(s7f);
	free(s7o);
	return(0);
}

int	ft_isascii(int c)
{
	return ((c >= 0 && c <= 127));
}

#endif

*/