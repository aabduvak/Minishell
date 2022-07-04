/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 00:04:00 by arelmas           #+#    #+#             */
/*   Updated: 2022/07/05 01:08:49 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static size_t	get_len(char strings[STR_I][CHR_I], size_t len);

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

static size_t	get_len(char strings[STR_I][CHR_I], size_t len)
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
