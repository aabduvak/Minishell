/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 00:13:41 by arelmas           #+#    #+#             */
/*   Updated: 2022/07/05 01:10:53 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	strings_bzero(char strings[STR_I][CHR_I], size_t count, size_t len)
{
	int	idx;

	idx = 0;
	while (idx < (int)len)
		ft_memset(strings[idx++], 0, count);
}
