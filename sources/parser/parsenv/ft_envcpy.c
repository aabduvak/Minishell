/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 03:05:07 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/05 03:05:20 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	envcpy(char *dst, char *src, size_t size)
{
	if (!src || !dst || !size)
		return ;
	while (*src && size--)
		*dst++ = *src++;
	*dst = 0;
}
