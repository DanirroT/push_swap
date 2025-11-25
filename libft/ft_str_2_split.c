/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_2_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:08:55 by dmota-ri          #+#    #+#             */
/*   Updated: 2025/10/30 11:06:48 by dmota-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordlen(const char *s, char c)
{
	int	res;

	res = 0;
	while (s[res] && s[res] != c)
		res++;
	return (res);
}

static int	ft_word_count(char const *s, char c)
{
	int	word_count;
	int	word;
	int	i;

	word = 0;
	word_count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && word == 0)
		{
			word = 1;
			word_count++;
		}
		else if (s[i] == c)
			word = 0;
		i++;
	}
	return (word_count);
}

static void	*trash(char **split, int i)
{
	while (i > 0)
		free(split[--i]);
	free(split);
	return (NULL);
}

static char	*ft_fill_word(char const *s, char c)
{
	size_t	word_len;
	char	*word;

	word_len = ft_wordlen(s, c);
	word = malloc(sizeof(char) * (word_len + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, s, word_len + 1);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;

	if (!s)
		return (NULL);
	split = malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			split[i] = ft_fill_word(s, c);
			if (!split[i])
				return (trash(split, i));
			i++;
			s += ft_wordlen(s, c);
		}
	}
	split[i] = NULL;
	return (split);
}

//	Allocates memory (using malloc(3)) and returns an array of strings
//		obtained by splitting ’s’ using the character ’c’ as a delimiter.
//		The array must end with a NULL pointer.

/*
#ifndef NO_MAIN

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
//	char	s4[] = "word";
//	char	**spit;

//	spit = ft_split(s4, 'o');
//	printf("split: %s : %s : %s : %s :\n", s4, spit[0], spit[1], spit[2]);

	char splitme[] = "--1-2--3---4----5-----42";
	char **tab = ft_split(splitme, '-');

	printf("split: %s\n\t : %c : %c : %c :\n",
		splitme, tab[0][2], tab[1][2], tab[2][2]);

	printf("\t : %c : %c : %c :\n", tab[3][2], tab[4][2], tab[5][2]);

//	printf("split: %s : %s : %s : %s :\n", s4, tab[0], tab[1], tab[2]);

//	printf("split: %s : %s : %s : %s :\n", s4, tab[0], tab[1], tab[2]);
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

#endif*/
