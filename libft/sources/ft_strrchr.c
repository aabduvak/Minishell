/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <abdulaziz.yosk@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 22:54:40 by aabduvak          #+#    #+#             */
/*   Updated: 2021/12/29 22:54:40 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	position;

	position = ft_strlen(str);
	if (str)
	{
		while (str[position] != (char) c && position >= 0)
			position--;
		if (str[position] == (char)c)
			return ((char *) &str[position]);
		return (NULL);
	}
	return (NULL);
}
