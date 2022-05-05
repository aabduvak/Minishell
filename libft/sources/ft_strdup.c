/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <abdulaziz.yosk@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 05:00:30 by aabduvak          #+#    #+#             */
/*   Updated: 2021/12/30 05:00:30 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*dest;
	size_t	leng;

	leng = ft_strlen(src) + 1;
	dest = malloc(sizeof(src[0]) * leng);
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, src, leng);
	return (dest);
}
