/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:58:29 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/08 19:03:18 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_cmdlist	*parse_line(char *line)
{
	char		*tmp;
	char		buf[STR_I][CHR_I];
	int			i;
	t_parser	data;
	t_cmdlist	*tmp_list;

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
			if (line[i - 1] == '$')
			{
				printf("TUUUUT\n");
				data.type = TENV;
			}
			buf[ft_get_stri(i - 1)][ft_get_chri(i - 1)] = line[i - 1];
		}
		line = tmp;
	}
	
	if (buf[0][0])
		end_block(&data.list, buf, data.type, i);
	tmp_list = data.list;
	printf("what?: %p\n", tmp_list);
	while (tmp_list)
	{
		printf("%s | ", tmp_list->cmd);
		if (tmp_list->type == TSTRING)
			printf("tstring | ");
		else if (tmp_list->type == TENV)
			printf("tenv | ");
		else
			printf("tcommand | ");
		if (tmp_list->piece)
			printf("piece\n");
		else
			printf("not piece\n");
		tmp_list = tmp_list->next;
	}
	return (data.list);
}
