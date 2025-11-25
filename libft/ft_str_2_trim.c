/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_2_trim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:25:07 by dmota-ri          #+#    #+#             */
/*   Updated: 2025/10/27 16:47:40 by dmota-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	c_in_set(char c, char const *set)
{
	size_t	j;

	j = 0;
	while (set[j])
	{
		if (c == set[j])
			return (1);
		j++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*start;
	char	*trim;
	size_t	i;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	len = ft_strlen(s1);
	i = 0;
	while (s1[i] && c_in_set(s1[i], set))
		i++;
	start = (char *)&s1[i];
	i = len - 1;
	while (i > 0 && c_in_set(s1[i], set))
		i--;
	len = ((&s1[i] - start) + 1);
	if (!*start)
		len = 0;
	trim = malloc(sizeof(char) * (len + 1));
	if (!trim)
		return (NULL);
	ft_strlcpy(trim, start, (len + 1));
	return (trim);
}
//	Allocates memory (using malloc(3)) and returns a copy of ’s1’
//		with characters from ’set’ removed from the beginning and the end.
/*
#ifndef NO_MAIN

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s3[] = "Hello World\n";
	char	set[] = "Helo Wrd\n";
	char	*trim;

	trim = ft_strtrim(s3, set);
	printf("\nstrtrim: %s trim: %s : %s :\n", s3, set, trim);




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
{
	size_t	i;

	i = 0;
	while ((i < dsize))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}

#endif
*/
