/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:18:28 by dmota-ri          #+#    #+#             */
/*   Updated: 2025/11/25 15:40:13 by dmota-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr_hex_fd(unsigned int n, int fd, char cap)
{
	int		c;
	char	*hex;
	size_t	prev;

	if (!(cap == 'x' || cap == 'X'))
		return (0);
	prev = 0;
	if (n / 16)
		prev += ft_putnbr_hex_fd(n / 16, fd, cap);
	c = (n % 16);
	if (cap == 'X')
		hex = ft_strdup("0123456789ABCDEF");
	if (cap == 'x')
		hex = ft_strdup("0123456789abcdef");
	c = hex[c];
	free(hex);
	return (write(fd, &c, 1) + prev);
}

size_t	ft_putptr_hex_fd(size_t n, int fd, char cap)
{
	int		c;
	char	*hex;
	size_t	prev;

	if (cap != 'p' && cap != 'x')
		return (0);
	if (!n)
		return (ft_putstr_fd("(nil)", fd));
	prev = 0;
	if (cap == 'p')
	{
		prev += ft_putstr_fd("0x", fd);
		cap = 'x';
	}
	if (n / 16)
		prev += ft_putptr_hex_fd(n / 16, fd, cap);
	c = (int)(n % 16);
	hex = ft_strdup("0123456789abcdef");
	c = hex[c];
	free(hex);
	return (write(fd, &c, 1) + prev);
}

size_t	ft_putunsi_fd(unsigned int n, int fd)
{
	size_t	i;
	int		c;
	size_t	prev;

	i = n;
	prev = 0;
	if (i / 10)
		prev += ft_putunsi_fd(i / 10, fd);
	c = (i % 10) + '0';
	return (write(fd, &c, 1) + prev);
}

size_t	ft_putstr_null_fd(void *s, int fd)
{
	int		i;
	char	*str;

	if (!s)
		return (ft_putstr_null_fd("(null)", fd));
	i = 0;
	str = (char *)s;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
	return (i);
}
/*
#ifndef NO_MAIN
# define NO_MAIN

#include <limits.h>
#include <stdio.h>

int	main(void)
{
	int		og1 = printf("_-_", "", "4", "", "2_");
	printf("\n");
	int		ft1 = ft_printf("_-_", "", "4", "", "2_");
	printf("\n\nRes");
	printf(": %i ", og1);
	printf(": %i ", ft1);
	printf("\n\n");


	//int		og2 = printf("\n NULL %s NULL ", NULL);
	//printf("\n");
	//int		ft2 = ft_printf("\n NULL %s NULL ", NULL);
	//printf("\n\nRes");
	//printf(": %i ", og2);
	//printf(": %i ", ft2);
	//printf("\n\n");
}

//	The function foo takes a string of format characters
//		and prints out  the  argument associated with each
//		format character based on the type.


size_t	check_percent(va_list *in, char c)
{
	size_t	len;

	len = 0;
	if (c == '%')
		len = ft_putchar_fd('%', 1);
	else if (c == 'd' || c == 'i')
		len = ft_putnbr_fd(va_arg(*in, int), 1);
	else if (c == 'u')
		len = ft_putunsi_fd(va_arg(*in, unsigned int), 1);
	else if (c == 'x' || c == 'X')
		len = ft_putnbr_hex_fd(va_arg(*in, unsigned int), 1, c);
	else if (c == 'p')
		len = ft_putptr_hex_fd((size_t)va_arg(*in, void *), 1, c);
	else if (c == 'c')
		len = ft_putchar_fd(va_arg(*in, int), 1);
	else if (c == 's')
		len = ft_putstr_fd(va_arg(*in, char *), 1);
	else
		return (-1);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	len;
	ssize_t	ret;
	va_list	in;

	if (!format)
		return (-1);
	va_start(in, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			ret = check_percent(&in, format[++i]);
			if (ret == -1)
				return (-1);
			len += ret;
		}
		else
			len += ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(in);
	return (len);
}

size_t	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
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

#endif
*/