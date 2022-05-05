/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <abdulaziz.yosk@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 05:50:53 by aabduvak          #+#    #+#             */
/*   Updated: 2021/12/28 05:50:53 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*a;
	char	*b;

	a = (char *) src;
	b = (char *) dest;
	if (a < b)
		while (len--)
			b[len] = a[len];
	else
		ft_memcpy(b, a, len);
	return (dest);
}
