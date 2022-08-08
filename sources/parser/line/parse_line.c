/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:58:29 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/08 17:04:04 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_cmdlist	*parse_line(char *line)
{
	char		*tmp;
	char		buf[STR_I][CHR_I];
	int			i;
	t_parser	data;

	i = 0;
	data.type = -1;
	data.list = 0;
	line = jump_space(line);
	strings_bzero(buf, 1, STR_I);
	while (line[i])
	{
		tmp = ft_parse_u(&data, buf, line, &i);
		if (!tmp)
			return (ft_cmdclear(&data.list, free));
		if (tmp == line && ++i)
		{
			data.type = TENV * (line[i - 1] == '$');
			buf[ft_get_stri(i - 1)][ft_get_chri(i - 1)] = line[i - 1];
		}
		line = tmp;
	}
	if (buf[0][0])
		end_block(&data.list, buf, data.type, i);
	return (data.list);
}
