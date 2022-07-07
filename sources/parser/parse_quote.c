/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:25:35 by arelmas           #+#    #+#             */
/*   Updated: 2022/07/08 02:30:38 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	
	*parse_quote(t_cmdlist **list, char buf[STR_I][CHR_I],
			char *line, int index)
{
	char	c;

	c = *(line++ + index);
	while (line[index] && line[index] != c)
	{
		buf[GET_STR_I(index)][GET_CHR_I(index)] = line[index];
		index++;
	}
	if (!line[index])
		return (NULL);
	line++;
	if (!line[index])
	{
		buf[GET_STR_I(index)][GET_CHR_I(index)] = 0;
		ft_cmdadd_back(list, ft_cmdnew(strings_join(buf, STR_I), TSTRING));
		strings_bzero(buf, 1, STR_I);
		return (jump_space(line + index));
	}
	return (line);
}
