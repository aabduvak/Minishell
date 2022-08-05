/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:58:29 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/05 04:42:10 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	
*parse(t_cmdlist **list, char buf[STR_I][CHR_I], char *line, int *index);

static void
	end_block(t_cmdlist **list, char buf[STR_I][CHR_I], int type, int index);

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
		tmp = ft_parse_u(data, buf, line, &index);
		if (!tmp)
			return (ft_cmdclear(data.list, free));
		if (tmp == line && ++index)
		{
			data.type = TENV * (line[index - 1] == '$');
			buf[GET_STR_I(index - 1)][GET_CHR_I(index - 1)] = line[index - 1];
		}
		line = tmp;
	}
	if (buf[0][0])
		end_block(data.list, buf, type, index);
	return (*(data.list));
}
