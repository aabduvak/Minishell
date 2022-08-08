/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:25:35 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/08 19:15:50 by arelmas          ###   ########.fr       */
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
		buf[ft_get_stri(index)][ft_get_chri(index)] = line[index];
		index++;
	}
	if (!line[index])
		return (NULL);
	buf[ft_get_stri(index)][ft_get_chri(index)] = 0;
	if (c == '"' && find_env(line - 1, 1))
		ft_cmdadd_back(list, ft_cmdnew(strings_join(buf, STR_I),
				TENV, line[index + 1] && line[index + 1] != ' '));
	else
		ft_cmdadd_back(list, ft_cmdnew(strings_join(buf, STR_I), TSTRING,
				line[index + 1] && line[index + 1] != ' '));
	strings_bzero(buf, 1, STR_I);
	return (jump_space(line + index + 1));
}
