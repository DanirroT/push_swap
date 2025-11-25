/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:23:34 by dmota-ri          #+#    #+#             */
/*   Updated: 2025/11/08 18:48:46 by dmota-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || fd >= FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	return (file_to_str(buffer, fd, line, 1));
}
/*
char	*get_next_line(int fd)
{
	static char	**stash;
	size_t		i;

	if (fd < 0 || fd >= FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
	{
		stash = malloc(FOPEN_MAX * sizeof(char *));
		if (!stash)
			return (NULL);
		i = 0;
		while (i < FOPEN_MAX)
			stash[i++] = NULL;
	}
	if (!stash[fd])
	{
		stash[fd] = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		stash[fd][0] = 0;
	}
	return (file_to_str(stash[fd], fd));
}*/
/*

int	main(void)
{
	char	*line;

	//int		fdE = open("EMIYA.txt", O_RDONLY);

	line = get_next_line(300);
	printf("\nline E1: %s\n", line);
	free(line);
}*/