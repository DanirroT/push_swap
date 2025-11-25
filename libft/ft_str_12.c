/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_12.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:45:14 by dmota-ri          #+#    #+#             */
/*   Updated: 2025/11/25 15:38:28 by dmota-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!s1)
		return (-s2[0]);
	if (!s2)
		return (s1[0]);
	i = 0;
	if (n > 0)
	{
		while (s1[i] && s2[i] && (i < n))
		{
			if (s1[i] != s2[i])
				return ((unsigned char)s1[i] - (unsigned char)s2[i]);
			i++;
		}
	}
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
//	The strcmp() function compares the two strings s1 and s2.
//		The locale is not taken into account
//		(for a locale-aware comparison,see strcoll(3)).
//		The comparison is done using unsigned characters.
//		strcmp() returns an integer indicating the result
//		of the comparison,as follows:
//
//		• 0, if the s1 and s2 are equal;
//		• a negative value if s1 is less than s2;
//		• a positive value if s1 is greater than s2.

// DONE

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!big)
		return (NULL);
	if (!little[0] || !little)
		return ((char *)big);
	while (big[i] && i < len)
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (little[j] && (i + j) < len && big[i + j] == little[j])
				j++;
			if (!little[j])
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}

//		The strstr() function locates the first occurrence of the
//		null-termi-nated string little in the null-terminated stringbig.

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dup;

	if (!s)
		return (NULL);
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
//	The strdup() function returns a pointer to a new string
//		which is a duplicate of the string s.
//		Memory for the new string is obtained with malloc(3),
//		and can be freed with free(3).
/*
#ifndef NO_MAIN

# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h> // bsd/ -lbsd


int	main(void)
{
//	char	s7[] = "Hello Werld\n";

//	char	s91[] = "12345 64789\n";
//	char	s92[] = "Hello World\n";
	char	*ft10;
	char	*og10;
//	char	s10[] = "Hello World";
//	printf("strncmp\t%i %i\n", 
//		ft_strncmp(NULL, NULL, 5),
//		strncmp(NULL, NULL, 5));
	ft10 = ft_strdup(NULL);
	og10 = strdup(NULL);
	printf("strdup\n\t%s in %p\n\t%s in %p", ft10, ft10, og10, og10);
//	free(ft10);
//	free(og10);
//	printf("strchr He:\t%p\t%p %c\n", ft_strnstr(s7, "He", 13), strstr(s7,
//			"He"), *ft_strnstr(s7, "He", 13));
//	printf("strchr He -1:\t%p\t%p %c\n", ft_strnstr(s7, "He", -1), strstr(s7,
//			"He"), *ft_strnstr(s7, "He", -1));
//	printf("strchr --:\t%p\t%p %c\n", ft_strnstr(s7, "", -1), strstr(s7, "He"),
//		*ft_strnstr(s7, "He", -1));
//	printf("strchr We:\t%p\t%p %c\n", ft_strnstr(s7, "We", 13), strstr(s7,
//			"We"), *ft_strnstr(s7, "We", 13));
//	printf("strchr We:\t%p\t%p\n", ft_strnstr(s7, "We", 3), strstr(s7, "We"));
//		//, *ft_strnstr(s7, "We", 3)
//	printf("strchr d\\n:\t%p\t%p\n", ft_strnstr(s7, "d\n", 3), strstr(s7,
//			"We")); //, *ft_strnstr(s7, "We", 3)
//	printf("strchr Help:\t%p\t%p\n", ft_strnstr(s7, "Help", 13), strstr(s7,
//			"Help")); // , *ft_strnstr(s7, "Help", 13)
}
int	ft_isascii(int c)
{
	return ((c >= 0 && c <= 127));
}
size_t	ft_strlen(const char *s)
{
	size_t	res;

	res = 0;
	while (s[res])
		res++;
	return (res);
}

#endif 
*/
