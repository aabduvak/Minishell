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
	t_cmdlist	*list;

	index = 0;
	data.type = -1;
	list = 0;
	line = jump_space(line);
	strings_bzero(buf, 1, STR_I);
	while (line[index])
	{
		printf("while\n");
		tmp = ft_parse_u(&data, buf, line, &index);
		if (!tmp)
			return (ft_cmdclear(list, free));
		if (tmp == line && ++index)
		{
			data.type = TENV * (line[index - 1] == '$');
			buf[GET_STR_I(index - 1)][GET_CHR_I(index - 1)] = line[index - 1];
		}
		line = tmp;
	}
	printf("exit\n");
	if (buf[0][0])
		end_block(list, buf, data.type, index);
	printf("ok: %p\n", data.list);
	return (*(data.list));
}
