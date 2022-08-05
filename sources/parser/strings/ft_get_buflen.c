/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_buflen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 02:56:43 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/05 02:57:29 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

size_t	ft_get_buflen(char strings[STR_I][CHR_I], size_t len)
{
	size_t	idx;
	size_t	jdx;
	size_t	strs_len;

	idx = 0;
	strs_len = 0;
	while (idx < len)
	{
		jdx = 0;
		while (strings[idx][jdx])
			jdx++;
		strs_len += jdx;
		idx++;
	}
	return (strs_len);
}
