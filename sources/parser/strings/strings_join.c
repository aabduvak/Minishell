/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 00:04:00 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/05 02:57:49 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*strings_join(char strings[STR_I][CHR_I], size_t len)
{
	size_t	idx;
	size_t	jdx;
	size_t	res_len;
	size_t	all_len;
	char	*res;

	idx = 0;
	res_len = 0;
	all_len = get_len(strings, len);
	res = (char *)malloc(sizeof(char) * (all_len) + 1);
	while (idx < len)
	{
		jdx = 0;
		while (strings[idx][jdx])
			res[res_len++] = strings[idx][jdx++];
		idx++;
	}
	res[res_len] = 0;
	return (res);
}
