/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <abdulaziz.yosk@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 23:29:41 by aabduvak          #+#    #+#             */
/*   Updated: 2022/06/28 07:57:16 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_strncmp(const char *str1, const char *str2, size_t size)
{
	size_t	i;

	i = 0;
	if ((!str1 && !str2) || size < 1)
		return (0);
	while (size - 1 > i && str1[i] == str2[i] && str1[i] && str2[i])
		i++;
	return ((unsigned char) str1[i] - (unsigned char)str2[i]);
}
