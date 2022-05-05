/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <abdulaziz.yosk@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 00:18:51 by aabduvak          #+#    #+#             */
/*   Updated: 2021/12/30 00:18:51 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t size)
{
	unsigned char	*ptr;

	while (size-- > 0)
	{
		ptr = (unsigned char *) str;
		if (*ptr == (unsigned char)c)
		{
			return (ptr);
		}
		str++;
	}
	return (NULL);
}
