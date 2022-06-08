/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:32:34 by aabduvak          #+#    #+#             */
/*   Updated: 2022/06/08 06:02:03 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

void	ft_putchar(int fd, char c, int *ret_val);
void	ft_putstr(int fd, char *str, int *ret_val);
size_t	ft_strlen(const char *str);
void	ft_convert(int fd, size_t num, char *repres, int *ret_val);
int		ft_printf(int fd, const char *str, ...);
void	ft_abs(int fd, int data, int *ret_val);

#endif