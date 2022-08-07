/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:58:29 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/05 10:46:05 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_cmdlist	*parse_line(char *line)
{
	char		*tmp;
	char		buf[STR_I][CHR_I];
	int			index;
	t_parser	data;

	index = 0;
	data.type = -1;
	data.list = 0;
	line = jump_space(line);
	strings_bzero(buf, 1, STR_I);
	while (line[index])
	{
		tmp = ft_parse_u(&data, buf, line, &index);
		if (!tmp)
			return (ft_cmdclear(&data.list, free));
		if (tmp == line && ++index)
		{
			data.type = TENV * (line[index - 1] == '$');
			buf[ft_get_stri(index - 1)][ft_get_chri(index - 1)] = line[index - 1];
		}
		line = tmp;
	}
	if (buf[0][0])
		end_block(&data.list, buf, data.type, index);
	return (data.list);
}
