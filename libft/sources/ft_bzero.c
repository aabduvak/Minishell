/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <abdulaziz.yosk@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 04:45:19 by aabduvak          #+#    #+#             */
/*   Updated: 2021/12/27 04:45:19 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *ptr, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *) ptr;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
	return (ptr);
}
