/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_22.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:41:33 by dmota-ri          #+#    #+#             */
/*   Updated: 2025/11/25 15:37:53 by dmota-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	ft_putchar_fd(char c, int fd)
{
	if (fd == -1)
		return ;
	write(fd, &c, 1);
}
//	Outputs the character ’c’ to the specified file descriptor.

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s || fd == -1)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
//	Outputs the string ’s’ to the specified file descriptor.

void	ft_putendl_fd(char *s, int fd)
{
	if (!s || fd == -1)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
//	Outputs the string ’s’ to the specified file descriptor
//		followed by a newline.

void	ft_putnbr_fd(int n, int fd)
{
	long int	i;
	int			c;

	if (fd == -1)
		return ;
	i = n;
	if (i < 0)
	{
		i = i * -1;
		write(fd, "-", 1);
	}
	if (i / 10)
	{
		ft_putnbr_fd(i / 10, fd);
	}
	c = (i % 10) + '0';
	write(fd, &c, 1);
}*/

size_t	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

size_t	ft_putstr_fd(void *s, int fd)
{
	int		i;
	char	*str;

	if (!s)
		return (-1);
	i = 0;
	str = (char *)s;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
	return (i);
}

size_t	ft_putendl_fd(void *s, int fd)
{
	size_t	i;

	if (!s || fd == -1)
		return (0);
	i = ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
	return (i + 1);
}

size_t	ft_putnbr_fd(int n, int fd)
{
	long int	i;
	int			c;
	size_t		prev;

	i = n;
	prev = 0;
	if (i < 0)
	{
		i = i * -1;
		prev = write(1, "-", 1);
	}
	if (i / 10)
	{
		prev += ft_putnbr_fd(i / 10, fd);
	}
	c = (i % 10) + '0';
	return (write(fd, &c, 1) + prev);
}

//	Outputs the integer ’n’ to the specified file descriptor.
/*
#ifndef NO_MAIN

# include <ctype.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int	main(int argc, char const *argv[])
{
	char	c7;
	int		file7;
	char	s8[] = "Hello World";
	int		file8;
	char	s9[] = "Hello World";
	int		file9;
	int		n0;
	int		file10;

	c7 = 'c';
	file7 = open("7.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	printf("\n - putchar_fd");
	ft_putchar_fd(c7, file7);
	file8 = open("8.txt", O_WRONLY, O_CREAT, O_TRUNC, 0644);
	printf("\n - putstr_fd");
	ft_putstr_fd(s8, file8);
	file9 = open("9.txt", O_WRONLY, O_CREAT, O_TRUNC, 0644);
	printf("\n - putendl_fd");
	ft_putendl_fd(s9, file9);
	n0 = -2147483648;
	//file10 = open("10.txt", O_WRONLY, O_CREAT, O_TRUNC, 0644);
	printf("\n - putnbr_fd");
	ft_putnbr_fd(n0, 1);
	close(file7);
	close(file8);
	close(file9);
	//close(file10);
}

#endif

*/