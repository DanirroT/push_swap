/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:52:28 by dmota-ri          #+#    #+#             */
/*   Updated: 2025/11/25 15:36:11 by dmota-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*s1;

	if (!s || !n)
		return ;
	i = 0;
	s1 = (unsigned char *)s;
	while (i < n)
	{
		s1[i] = 0;
		i++;
	}
}
//	The bzero() function erases the data in the n bytes of the memory
//		starting at the location pointed to by s,by writing zeros
//		(bytes containing '\0') to that area.

// DONE

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	c1;

	if (!s || !n)
		return (NULL);
	s1 = (unsigned char *)s;
	c1 = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (s1[i] == c1)
			return ((void *)&s1[i]);
		i++;
	}
	return (NULL);
}

//	The memchr() function scans the initial n bytes of the memory
//		area pointed to by s for the first instance of c.
//		Both c and the bytes of the memory area pointed to by s
//		are interpreted as unsigned char.

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*c1;
	unsigned char	*c2;

	if (!n)
		return (0);
	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	if (!s1)
		return (-c2[0]);
	if (!s2)
		return (c1[0]);
	i = 0;
	if (n > 0)
	{
		while (i < n)
		{
			if (c1[i] != c2[i])
			{
				return (c1[i] - c2[i]);
			}
			i++;
		}
	}
	return (0);
}

//	The memcmp() function compares the first n bytes
//		(each interpreted as unsigned char) of thememory areas s1 and s2

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*d1;

	if (!n || !dest)
		return (NULL);
	if (!src)
		return (dest);
	s1 = (unsigned char *)src;
	d1 = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		d1[i] = s1[i];
		i++;
	}
	return (d1);
}

//	The memcpy() function copies n bytes from memory area
//		src to memory area dest. The memory areas must not overlap.
//		Use memmove(3) if the memory areas do overlap.

// DONE

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*d1;

	if (!n || !dest)
		return (NULL);
	if (!src)
		return (dest);
	s1 = (unsigned char *)src;
	d1 = (unsigned char *)dest;
	if (src > dest)
	{
		i = 0;
		while (i < n)
		{
			d1[i] = s1[i];
			i++;
		}
	}
	else
	{
		while (n--)
			d1[n] = s1[n];
	}
	return (d1);
}

//	The memmove() function copies n bytes from memory area src to memory
//		area dest. The memory areas may overlap: copying takes place as
//		though the bytes in src are first copied into a temporary array
//		that does not overlap src or dest, and the bytes are then copied
//		from the temporary array to dest.

/*
#ifndef NO_MAIN

# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main(void)
{
//	char	src[] = "coucou";
//	char	destf[11] = "AAAAAAAAAA\0";
//	char	desto[11] = "AAAAAAAAAA\0";
	
	char *ft = memmove(NULL, NULL, 2);
	write(1, "og ", 3);
	char *og = ft_memmove(NULL, NULL, 2);
	write(1, "ft\n", 3);
	printf("\nNull:\tft:_%c_%c_\t%p\tog:_%c_%c_\t%p",  destf[0], destf[1], ft,
		desto[0], desto[1], og);
	return 0;
}

void	printBinaryWithPadding(int num)
{
	int	i;

	for (i = sizeof(int) * 8 - 1; i >= 0; i--) {
		printf("%d", (num >> i) & 1);
		if (i % 4 == 0) printf(" "); // Group by 4 bits for readability
	}
	printf("\n");
}

int	main(void)
{
	char	s2[] = "12345";
	char	s31[] = "abcde";
	char	s32[] = "12345";
	char	s4f[] = "12345";
	char	s4o[] = "12345";
	char	d4f[] = "abcde";
	char	d4o[] = "abcde";
	char	cmps[] = {-1, 0, 127, 0};
	char	cmpsCpy[] = {-64, 0, 127, 0};
	char	cmps2[] = {0, 0, 127, 0};
	char	cmps3[] = {0, 0, 42, 0};

//	char	s1f[] = "12345";
//	char	s1o[] = "12345";
//	char    s[] = { 0, 1, 2, 3, 4, 5 };
//	char	s5f[] = "12345";
//	char	filler1[] = "\0\0\0\0\0\0\0\0\0\0";
//	char	s5o[] = "12345";
//	char	*d5f;
//	char	*d5o;
//	char	s5f2[] = "12345";
//	char	filler2[] = "\0\0\0\0\0\0\0\0\0\0";
//	char	s5o2[] = "12345";
//	char	*d5f2;
//	char	*d5o2;
//	ft_bzero(s1f, 3);
//	bzero(s1o, 3);
//	printf("\nbzero\n1 ft: %i ; og: %i\n", s1f[1], s1o[1]);
//	printf("2 ft: %i ; og: %i\n", s1f[2], s1o[2]);
//	printf("3 ft: %i ; og: %i\n", s1f[3], s1o[3]);
//	printf("4 ft: %i ; og: %i\n", s1f[4], s1o[4]);
//	printf("\nmemchr\tft: %p ; og: %p\n", ft_memchr(s2, '4', 3), memchr(s2, '4',
			3));
//	printf("\nmemchr\tft2: %i ; og2: %i\n", ft_memchr(s, 2+256, 3), memchr(s,
			2+256, 3));
	printf("\nmemcmp\tft: %i ; og: %i\n", ft_memcmp(s31, s32, 3), memcmp(s31,
			s32, 3));
	printf("\nmemcmp 3\tft: %i ; og: %i\n", ft_memcmp(cmps, cmps2, 1),
		memcmp(cmps, cmps2, 1));
	printf("\nmemcmp 4\tft: %i ; og: %i\n", ft_memcmp(cmps2, cmps, 1),
		memcmp(cmps2, cmps, 1));
	printf("\nbinary s2 ");
	printBinaryWithPadding(cmps[0]);
	printf("\nbinary ft ");
	printBinaryWithPadding(ft_memcmp(cmps2, cmps, 1));
	printf("\nbinary og ");
	printBinaryWithPadding(memcmp(cmps2, cmps, 1));
	printf("\n");
	ft_memcpy(d4f, s4f, 3);
	memcpy(d4o, s4o, 3);
	printf("\nmemcpy\tft: %s ; og: %s\n", d4f, d4o);
//	printf("\nmemmove front:\n\tft: %s\ton %p\n\tog: %s\ton %p\n", s5f, s5f,
		s5o, s5o);
//	d5f = ft_memmove(s5f+2, s5f, 4);
//	d5o = memmove(s5f+2, s5o, 4);
//	printf("\nft:\t%s\ton %p \n\t%s\ton %p\n\nog:\t%s\ton %p\n\t%s\ton %p\n",
//		s5f, s5f, d5f, d5f, s5o, s5o, d5o, d5o);
//	printf("\nmemmove back:\n\tft: %s\ton %p\n\tog: %s\ton %p\n", s5f2, s5f2,
		s5o2, s5o2);
//	d5f2 = ft_memmove(s5f2, s5f2+2, 4);
//	d5o2 = memmove(s5f2, s5o2+2, 4);
//	printf("\nft:\t%s\ton %p \n\t%s\ton %p\n\nog:\t%s\ton %p\n\t%s\ton %p\n",
//		s5f2, s5f2, d5f2, d5f2, s5o2, s5o2, d5o2, d5o2);
//	printf("Fillers: %c %c\n", filler1[1], filler2[1]);
	return (0);
}

int	ft_isascii(int c)
{
	return ((c >= 0 && c <= 127));
}

#endif

*/
