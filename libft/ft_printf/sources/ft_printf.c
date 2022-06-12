/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:32:26 by aabduvak          #+#    #+#             */
/*   Updated: 2022/06/12 07:44:17 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @file ft_printf.c
 * @author Abdulaziz Abduvakhobov (abdulaziz.yosk@gmail.com)
 * @brief The function ft_controller() checks the ch to related printf
 * flags and if condition matches calls needed function and returns 0
 * else returns -1
 * 
 * @param ch - character after %
 * @param list - list of arguments
 * @param ret_val - number of characters which function must print
 * @return int - status of operation (0 -> successfull: -1 -> failed)
 * 
 * @version 1.0.1
 * @date 2022-01-21
 * 
 * @copyright Copyright (c) 2022 
 */

static int	ft_controller(char ch, va_list list, int *ret_val, int fd)
{
	if (ch == 'c')
		ft_putchar(fd, va_arg(list, int), ret_val);
	else if (ch == 's')
		ft_putstr(fd, va_arg(list, char *), ret_val);
	else if (ch == 'd' || ch == 'i')
		ft_abs(fd, va_arg(list, int), ret_val);
	else if (ch == 'u')
		ft_convert(fd, va_arg(list, unsigned int), "0123456789", ret_val);
	else if (ch == 'x')
		ft_convert(fd, va_arg(list, unsigned int),
			"0123456789abcdef", ret_val);
	else if (ch == 'X')
		ft_convert(fd, va_arg(list, unsigned int),
			"0123456789ABCDEF", ret_val);
	else if (ch == 'p')
	{
		ft_putstr(fd, "0x", ret_val);
		ft_convert(fd, va_arg(list, unsigned long),
			"0123456789abcdef", ret_val);
	}
	else if (ch == '%')
		ft_putchar(fd, '%', ret_val);
	else
		return (-1);
	return (0);
}

/**
 * @file ft_printf.c
 * @author Abdulaziz Abduvakhobov (abdulaziz.yosk@gmail.com)
 * @brief The function ft_printf() (the name comes from “print formatted”)
 * prints a string on the screen using a “format string” that includes
 * the instructions to mix several strings and produce the final string
 * to be printed on the screen.
 * 
 * @param str - the formating string
 * @param ... - list of arguments
 * @return int - number of characters which were printed
 * 
 * @version 1.0.1
 * @date 2022-01-21
 * 
 * @copyright Copyright (c) 2022 
 */

int	ft_printf(int fd, const char *str, ...)
{
	va_list	list;
	int		is_empty;
	int		ret_val;

	ret_val = 0;
	va_start(list, str);
	while (*str)
	{
		if (*str == '%')
		{
			is_empty = 0;
			while (*(++str) == 32)
				is_empty = 1;
			if (is_empty)
				ft_putchar(fd, ' ', &ret_val);
			if (ft_controller(*str, list, &ret_val, fd) != 0)
				ret_val += write(fd, str, 1);
		}
		else
			ret_val += write(fd, str, 1);
		str++;
	}
	va_end(list);
	return (ret_val);
}
