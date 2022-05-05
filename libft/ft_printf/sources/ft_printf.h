/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42ISTANBUL.COM.TR>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:32:34 by aabduvak          #+#    #+#             */
/*   Updated: 2022/02/15 16:57:57 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

void	ft_putchar(char c, int *ret_val);
void	ft_putstr(char *str, int *ret_val);
size_t	ft_strlen(const char *str);
void	ft_convert(size_t num, char *repres, int *ret_val);
int		ft_printf(const char *str, ...);
void	ft_abs(int data, int *ret_val);

#endif