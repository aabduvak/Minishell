/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:58:29 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/09 11:36:47 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static	void	set_parser(t_parser *parser)
{
	parser->type = -1;
	parser->list = 0;
}

t_cmdlist	*parse_line(char *line)
{
	char		*tmp;
	char		buf[STR_I][CHR_I];
	int			i;
	t_parser	data;

	i = 0;
	set_parser(&data);
	line = jump_space(line);
	strings_bzero(buf, 1, STR_I);
	while (line[i])
	{
		tmp = ft_parse_u(&data, buf, line, &i);
		if (!tmp)
			return (ft_cmdclear(&data.list, free));
		if (tmp == line && ++i)
		{
			if (line[i - 1] == '$')
				data.type = TENV;
			buf[ft_get_stri(i - 1)][ft_get_chri(i - 1)] = line[i - 1];
		}
		line = tmp;
	}
	if (buf[0][0])
		end_block(&data.list, buf, data.type, i);
	return (data.list);
}
