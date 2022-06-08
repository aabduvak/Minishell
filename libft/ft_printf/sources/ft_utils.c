/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:49:53 by aabduvak          #+#    #+#             */
/*   Updated: 2022/06/08 06:01:28 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar(int fd, char c, int *ret_val)
{
	*ret_val += write(fd, &c, 1);
}

void	ft_putstr(int fd, char *s, int *ret_val)
{
	if (!s)
	{
		ft_putstr(fd, "(null)", ret_val);
		return ;
	}
	while (*s)
	{
		ft_putchar(fd, *s, ret_val);
		s++;
	}
}

void	ft_convert(int fd, size_t num, char *repres, int *ret_val)
{
	static char	buffer[50];
	char		*ptr;
	int			base;

	base = ft_strlen(repres);
	ptr = &buffer[49];
	*ptr = '\0';
	*--ptr = repres[num % base];
	num /= base;
	while (num != 0)
	{
		*--ptr = repres[num % base];
		num /= base;
	}
	return (ft_putstr(fd, ptr, ret_val));
}

void	ft_abs(int fd, int data, int *ret_val)
{
	if (data < 0)
	{
		ft_putchar(fd, '-', ret_val);
		if (data == -2147483648)
			return (ft_convert(fd, 2147483648, "0123456789", ret_val));
		return (ft_convert(fd, -data, "0123456789", ret_val));
	}
	return (ft_convert(fd, data, "0123456789", ret_val));
}
