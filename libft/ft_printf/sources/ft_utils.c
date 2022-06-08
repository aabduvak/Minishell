/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:49:53 by aabduvak          #+#    #+#             */
/*   Updated: 2022/06/08 03:33:44 by aabduvak         ###   ########.fr       */
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

void	ft_putchar(char c, int *ret_val)
{
	*ret_val += write(1, &c, 1);
}

void	ft_putstr(char *s, int *ret_val)
{
	if (!s)
	{
		ft_putstr("(null)", ret_val);
		return ;
	}
	while (*s)
	{
		ft_putchar(*s, ret_val);
		s++;
	}
}

void	ft_convert(size_t num, char *repres, int *ret_val)
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
	return (ft_putstr(ptr, ret_val));
}

void	ft_abs(int data, int *ret_val)
{
	if (data < 0)
	{
		ft_putchar('-', ret_val);
		if (data == -2147483648)
			return (ft_convert(2147483648, "0123456789", ret_val));
		return (ft_convert(-data, "0123456789", ret_val));
	}
	return (ft_convert(data, "0123456789", ret_val));
}
