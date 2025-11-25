/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_11.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:45:14 by dmota-ri          #+#    #+#             */
/*   Updated: 2025/11/25 15:38:54 by dmota-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	res;

	if (!s)
		return (0);
	res = 0;
	while (s[res])
		res++;
	return (res);
}

//	The strlen() function calculates the length of the string pointed to by s,
//		excluding the terminating null byte ('\0').

// DONE

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
// Copy a string with truncation.
{
	size_t	i;

	if (!src)
		return (0);
	if (dsize == 0 || !dst)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && (i < dsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
//	see man, too mush to put here

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
// Copy a string with truncation.
{
	size_t	i;
	size_t	j;
	size_t	dst_len;

	dst_len = ft_strlen(dst);
	if (dsize == 0 || dsize <= dst_len)
		return (dsize + ft_strlen(src));
	i = dst_len;
	j = 0;
	while ((src[j]) && (i < (dsize - 1)))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst_len + ft_strlen(src));
}
//	see man, too mush to put here

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	c1;

	if (!s)
		return (NULL);
	c1 = (unsigned char)c;
	i = 0;
	while ((s[i]))
	{
		if (s[i] == c1)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == c1)
		return ((char *)&s[i]);
	return (NULL);
}
//	The strchr() function returns a pointer to the first
//		occurrence of the character c in the string s.

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	c1;

	if (!s)
		return (NULL);
	c1 = (unsigned char)c;
	i = ft_strlen(s);
	while (i)
	{
		if (s[i] == c1)
			return ((char *)&s[i]);
		i--;
	}
	if (s[i] == c1)
		return ((char *)&s[i]);
	return (NULL);
}

//	The strrchr() function returns a pointer to the last
//		occurrence of the character c in the string s.
/*
#ifndef NO_MAIN

# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h> // bsd/ -lbsd

int	main(void)
{
	char	src[] = "coucou";
	char	destf[11] = "AAAAAAAAAA\0";
	char	desto[11] = "AAAAAAAAAA\0";
	char	dest1[11] = "AAAAAAAAAA\0";
	char	dest2[11] = "AAAAAAAAAA\0";
	int		ft;
	int		og;
//	char	s6[] = "World-12";
//	int		len;
//	char	dst6o[20] = "Hello ";
//	char	dst6f[20] = "Hello ";
//	int		ft6;
//	int		og6;

	printf("ft_strlcpy\t: ");
	printf("\ncheck:\tft:%s\tog:%s",  destf, desto);
	ft = ft_strlcpy(dest1, src, strlen(src));
	og = strlcpy(dest2, src, strlen(src));
	printf("\nlen:\tft:%s\t%i\tog:%s\t%i",  dest1, ft, dest2, og);
	ft = ft_strlcpy(destf, src, 0);
	og = strlcpy(desto, src, 0);
	printf("\n0:\tft:_%c_%c_\t%i\tog:_%c_%c_\t%i",  destf[0], destf[1], ft,
	desto[0], desto[1], og);
	ft = ft_strlcpy(destf, src, 1);
	og = strlcpy(desto, src, 1);
	printf("\n1:\tft:_%c_%c_\t%i\tog:_%c_%c_\t%i",  destf[0], destf[1], ft,
	desto[0], desto[1], og);
	ft = ft_strlcpy(destf, src, 2);
	og = strlcpy(desto, src, 2);
 	printf("\n2:\tft:_%c_%c_\t%i\tog:_%c_%c_\t%i",  destf[0], destf[1], ft,
	desto[0], desto[1], og);

	ft = ft_strlcpy(NULL, NULL, 2);
	og = strlcpy(NULL, NULL, 2);
	printf("\nNull:\tft:_%c_%c_\t%i\tog:_%c_%c_\t%i",  destf[0], destf[1], ft,
	desto[0], desto[1], og);
//	ft = ft_strlcpy(destf, src, -1);
//	og = strlcpy(desto, src, -1);
//	printf("\n-1:\tft:%s\t%i\tog:%s\t%i",  destf, ft, desto, og);
//	memset(destf, 'A', 10);
//	memset(desto, 'A', 10);
//	ft = ft_strlcpy(destf, src, 6);
//	og = strlcpy(desto, src, 6);
//	printf("\n6:\tft:%s\t%i\tog:%s\t%i",  destf, ft, desto, og);
//	memset(destf, 'A', 10);
//	memset(desto, 'A', 10);
//	ft = ft_strlcpy(destf, src, 7);
//	og = strlcpy(desto, src, 7);
//	printf("\n7:\tft:%s\t%i\tog:%s\t%i",  destf, ft, desto, og);
//	memset(destf, 'A', 10);
//	memset(desto, 'A', 10);
//	ft = ft_strlcpy(destf, src, 8);
//	og = strlcpy(desto, src, 8);
//	printf("\n8:\tft:%s\t%i\tog:%s\t%i",  destf, ft, desto, og);
//	memset(destf, 'A', 10);
//	memset(desto, 'A', 10);
//	ft = ft_strlcpy(destf, "", 42);
//	og = strlcpy(desto, "", 42);
//	printf("\n42:\tft:%s\t%i\tog:%s\t%i",  destf, ft, desto, og);
//	memset(destf, 0, 10);
//	memset(desto, 0, 10);
//	ft = ft_strlcpy(destf, "1", 0);
//	og = strlcpy(desto, "1", 0);
//	printf("\n0 (1):\tft:%s\t%i\tog:%s\t%i",  destf, ft, desto, og);
//	memset(destf, 'A', 10);
//	memset(desto, 'A', 10);
//	write(1, "\n", 1);
}

int	main(void)
{
	//	char	s1[] = "123";
	//	char	s8[] = "Hello Werld\n";
	//	char	c8;
	//	printf("len\t%lu %lu\n", ft_strlen(s1), strlen(s1));
	len = strlen(s6) + strlen(dst6f);
	ft6 = ft_strlcat(dst6f, s6, 2);
	og6 = strlcat(dst6o, s6, 2);
	printf("strlcat %i\n\tft: %s - %i\n\tog: %s - %i\n", len, dst6f, ft6, dst6o,
		og6);
	//	char	s7[] = "Hello Werld\n";
	//	char c7 = 'e';
	//	printf("strchr e:\t%p %p %c\n", ft_strchr(s7, c7), strchr(s7, c7),
			*ft_strchr(s7, c7));
	//	c7 = 0;
	//	printf("strchr 0:\t%p %p %c\n", ft_strchr(s7, c7), strchr(s7, c7),
			*ft_strchr(s7, c7));
	//	char c8 = 'H';
	//	printf("strrchr H\t%p %p %c\n", ft_strrchr(s7, c8), strrchr(s7, c8),
			*ft_strrchr(s7, c8));
	//	c8 = 0;
	//	printf("strrchr 0\t%p %p %c\n", ft_strrchr(s7, c8), strrchr(s7, c8),
			*ft_strrchr(s7, c8));
	//	c8 = 'e';
	//	printf("strrchr e\t%p %p %c\n", ft_strrchr(s7, c8), strrchr(s7, c8),
			*ft_strrchr(s7, c8));
	//	printf("strrchr H\t%p %p %c\n", ft_strrchr(s7, 'H'), strrchr(s7, 'H'),
			*ft_strrchr(s7, 'H'));
	//	printf("strrchr H++\t%p %p %c\n", ft_strrchr(s7, 'H' + 256), strrchr(s7,
				'H' + 256), *ft_strrchr(s7, 'H' + 256));
}


#endif
*/
