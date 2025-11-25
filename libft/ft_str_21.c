/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_21.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:51:03 by dmota-ri          #+#    #+#             */
/*   Updated: 2025/10/28 16:08:33 by dmota-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Aditional Functions

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, &s[start], (len + 1));
	return (sub);
}
//	Allocates memory (using malloc(3)) and returns a substring
//		from the string ’s’. The substring starts at index ’start’
//		and has a maximum length of ’len’.

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*join;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	join = malloc(sizeof(char) * (len));
	if (!join)
		return (NULL);
	ft_strlcpy(join, s1, (len));
	ft_strlcat(join, s2, (len));
	return (join);
}
//	Allocates memory (using malloc(3)) and returns a new string,
//		which is the result of concatenating ’s1’ and ’s2’.

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*res;

	if (!s)
		return (NULL);
	if (!f)
		return (ft_strdup(s));
	res = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
//	Applies the function f to each character of the string s,
//		passing its index as the first argument and the character
//		itself as the second. A new string is created (using malloc(3))
//		to store the results from the successive applications of f.

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
//	Applies the function ’f’ to each character of the string passed as argument,
//		passing its index as the first argument. Each character is passed by
//		address to ’f’ so it can be modified if necessary.

/*
#ifndef NO_MAIN

# include <ctype.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

char	f5(unsigned int n, char c)
{
	if (n == 2)
		return ('2');
	return (c);
}

void	f6(unsigned int n, char *c)
{
	n++;
	write(1, c, 1);
}


int	main(void)
{
	char	s1[] = "Hello World\n";
	char	*sub;
	char	s21[] = "Hello ";
	char	s22[] = "World\n";
	char	*join;
	char	s5[] = "Hello World\n";
	char	*map;
	char	s6[] = "Hello World\n";
	char	*ss2;
	char	*ss3;
	char	*ss10;
	char	*ss13;
	char	*ss15;

//	sub = ft_substr(s1, 5, 7);
//	printf("substr: %s : %s\n", s1, sub);
//	join = ft_strjoin(s21, s22);
//	printf("\nstrjoin: %s & %s : %s :\n", s21, s22, join);
	ss2 = ft_substr("tripouille", 0, 42000);
	ss3 = ft_substr("tripouille", 1, 1);
	ss10 = ft_substr("0123456789", 9, 10);
	ss13 = ft_substr("BONJOUR LES HARICOTS !", 8, 14);
	ss15 = ft_substr("test", 1, 2);
	printf("substr:\n");
	printf("\t%s\t%s\n", "tripouille", ss2);
	printf("\t%s\t%s\n", "tripouille", ss3);
	printf("\t%s\t%s\n", "0123456789", ss10);
	printf("\t%s\t%s\n", "BONJOUR LES HARICOTS !", ss13);
	printf("\t%s\t%s\n", "test", ss15);
	free(ss2);
	free(ss3);
	free(ss10);
	free(ss13);
	free(ss15);
//	map = ft_strmapi(s5, &f5);
//	printf("strmapi: %s : %s :\n", s5, map);
//	printf("striteri: %s : ", s6);
//	ft_striteri(s6, &f6);
}

size_t	ft_strlen(const char *s)
{
	size_t	res;

	res = 0;
	while (s[res])
		res++;
	return (res);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
// Copy a string with truncation.
{
	size_t	i;

	if (dsize == 0)
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

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dup;

	dup = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

#endif
*/
