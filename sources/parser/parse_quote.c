/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:25:35 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/01 18:30:52 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int
find_env(char *line);

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
	if (is_endcmd(line[index]) || !line[index])
	{
		buf[GET_STR_I(index)][GET_CHR_I(index)] = 0;
		if (c == '"' && find_env(line - 1))
			ft_cmdadd_back(list, ft_cmdnew(strings_join(buf, STR_I), TENV));
		else
			ft_cmdadd_back(list, ft_cmdnew(strings_join(buf, STR_I), TSTRING));
		strings_bzero(buf, 1, STR_I);
		return (jump_space(line + index));
	}
	return (line + index);
}

static int
	find_env(char *line)
{
	while (line && *line && *line != '$')
		line++;
	if (!*line || !check_env(line + 1))
		return (0);
	return (1);
}
