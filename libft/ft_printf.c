/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:18:28 by dmota-ri          #+#    #+#             */
/*   Updated: 2025/11/25 15:40:46 by dmota-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		len = ft_putstr_null_fd(va_arg(*in, char *), 1);
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
