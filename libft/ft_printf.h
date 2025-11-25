/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:01:18 by dmota-ri          #+#    #+#             */
/*   Updated: 2025/11/20 12:11:38 by dmota-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

size_t	ft_putnbr_hex_fd(unsigned int n, int fd, char cap);

size_t	ft_putptr_hex_fd(size_t n, int fd, char cap);

size_t	ft_putunsi_fd(unsigned int n, int fd);

size_t	ft_putstr_null_fd(void *s, int fd);

size_t	check_percent(va_list *in, char c);

int		ft_printf(const char *format, ...);

#endif