/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <abdulaziz.yosk@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:23:44 by aabduvak          #+#    #+#             */
/*   Updated: 2022/01/05 14:23:44 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f) (unsigned int, char *))
{
	unsigned int	index;

	index = 0;
	if (s != NULL && f != NULL)
	{
		while (s[index] != '\0')
		{
			f(index, &s[index]);
			index++;
		}
	}
}
