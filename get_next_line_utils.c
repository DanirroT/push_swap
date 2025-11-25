/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:23:36 by dmota-ri          #+#    #+#             */
/*   Updated: 2025/11/08 18:48:40 by dmota-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*trash(void *temp)
{
	if (temp)
		free(temp);
	return (NULL);
}

ssize_t	ft_strchr_n(const char *s)
{
	ssize_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

char	*ft_buffjoin(char *temp, char *buff, ssize_t buff_len)
{
	ssize_t	temp_len;
	char	*join;
	char	*temp_start;
	char	*join_start;

	temp_len = ft_strchr_n(temp);
	if (!buff || temp_len + buff_len + (buff[buff_len] == '\n') == 0)
		return (trash(temp));
	join = malloc((temp_len + buff_len + 1 + (buff[buff_len] == '\n')));
	if (!join)
		return (trash(temp));
	join_start = join;
	temp_start = temp;
	while (temp && *temp)
		*join++ = *temp++;
	while (buff_len-- > 0)
		*join++ = *buff++;
	if (*buff == '\n')
		*join++ = '\n';
	*join++ = '\0';
	return (trash(temp_start), join_start);
}

char	*file_to_str(char *buffer, int fd, char *line, ssize_t	res)
{
	char	*buff_sep;
	ssize_t	buff_len;

	if (!buffer || fd >= FOPEN_MAX || fd < 0)
		return (NULL);
	if (buffer[0])
		line = ft_buffjoin(line, buffer, ft_strchr_n(buffer));
	while ((!line || line[ft_strchr_n(line)] != '\n'))
	{
		res = read(fd, buffer, BUFFER_SIZE);
		if (res <= 0)
			break ;
		buffer[res] = 0;
		line = ft_buffjoin(line, buffer, ft_strchr_n(buffer));
	}
	buff_len = ft_strchr_n(buffer);
	if (res != -1 && buffer[buff_len] == '\n')
	{
		buff_sep = buffer + buff_len + 1;
		while (*buff_sep)
			*buffer++ = *buff_sep++;
	}
	if (res == -1)
		return (*buffer = '\0', trash(line));
	return (*buffer = '\0', line);
}
/*
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || fd >= FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	return (file_to_str(buffer, fd, line, 1));
}

int	main(void)
{
	char	*line;

	//line = get_next_line(2000);
	//printf("\nline invalid1: %s\n", line);
	//trash(line);

	int		fdE = open("EMIYA.txt", O_RDONLY);

	line = get_next_line(fdE);
	printf("\nline E1: %s\n", line);
	trash(line);

	close(fdE);

	line = get_next_line(fdE);
	printf("\nline E1: %s\n", line);
	trash(line);
}*/

	//trash(stash[fdE]);

	//line = get_next_line(fdE);
	//printf("\nline E_error1: %s\n", line);
	//trash(line);

	//line = get_next_line(fdE);
	//printf("\nline E2: %s\n", line);
	//trash(line);
	//line = get_next_line(fdE);
	//printf("\nline E3: %s\n", line);
	//trash(line);
	//line = get_next_line(fdE);
	//printf("\nline E4: %s\n", line);
	//trash(line);
	//line = get_next_line(fdE);
	//printf("\nline E5: %s\n", line);
	//trash(line);
	//line = get_next_line(fdE);
	//printf("\nline E6: %s\n", line);
	//trash(line);
	//line = get_next_line(fdE);
	//printf("\nline E7: %s\n", line);
	//trash(line);
	//line = get_next_line(fdE);
	//printf("\nline E8: %s\n", line);
	//trash(line);
	//line = get_next_line(fdE);
	//printf("\nline E9: %s\n", line);
	//trash(line);
	//line = get_next_line(fdE);
	//printf("\nline E0: %s\n", line);
	//trash(line);
	//line = get_next_line(fdE);
	//printf("\nline E1: %s\n", line);
	//trash(line);
	//line = get_next_line(fdE);
	//printf("\nline E2: %s\n", line);
	//trash(line);
	//line = get_next_line(fdE);
	//printf("\nline E3: %s\n", line);
	//trash(line);

	//int		fdS = open("Summoning.txt", O_RDONLY);

	//line = get_next_line(fdS);
	//printf("\nline S1: %s\n", line);
	//trash(line);
	//line = get_next_line(fdS);
	//printf("\nline S2: %s\n", line);
	//trash(line);
	//line = get_next_line(fdS);
	//printf("\nline S3: %s\n", line);
	//trash(line);
	//line = get_next_line(fdS);
	//printf("\nline S4: %s\n", line);
	//trash(line);
	//line = get_next_line(fdS);
	//printf("\nline S5: %s\n", line);
	//trash(line);
	//line = get_next_line(fdS);
	//printf("\nline S6: %s\n", line);
	//trash(line);
	//line = get_next_line(fdS);
	//printf("\nline S7: %s\n", line);
	//trash(line);
	//line = get_next_line(fdS);
	//printf("\nline S8: %s\n", line);
	//trash(line);
	//line = get_next_line(fdS);
	//printf("\nline S9: %s\n", line);
	//trash(line);
	//line = get_next_line(fdS);
	//printf("\nline S0: %s\n", line);
	//trash(line);
	//line = get_next_line(fdS);
	//printf("\nline S1: %s\n", line);
	//trash(line);
	//line = get_next_line(fdS);
	//printf("\nline S2: %s\n", line);
	//trash(line);
	//line = get_next_line(fdS);
	//printf("\nline S3: %s\n", line);
	//trash(line);
	//line = get_next_line(fdS);
	//printf("\nline S4: %s\n", line);
	//trash(line);
	//line = get_next_line(fdS);
	//printf("\nline S5: %s\n", line);
	//trash(line);

	//close(fdS);

	//line = get_next_line(fdS);
	//printf("\nline Invalid: %s\n", line);
	//trash(line);
/*
	line = get_next_line(0);
	printf("\nline 0: %s\n", line);
	trash(line);
	line = get_next_line(1);
	printf("\nline 1: %s\n", line);
	trash(line);

	int		fde = open("Empty.txt", O_RDONLY);
	int		fd1 = open("1char.txt", O_RDONLY);
	int		fd41 = open("41_nl.txt", O_RDONLY);
	line = get_next_line(fde);
	printf("\nline e: %s\n", line);
	trash(line);
	line = get_next_line(fd1);
	printf("\nline 1: %s\n", line);
	trash(line);
	line = get_next_line(fd41);
	printf("\nline 41: %s\n", line);
	trash(line);
	line = get_next_line(fd41);
	printf("\nline 41: %s\n", line);
	trash(line);
	write(1, "1\0a", 3);
	close(fd1);
	close(fde);
	close(fd41);*/
//}