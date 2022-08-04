/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:58:29 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/04 20:28:56 by arelmas          ###   ########.fr       */
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
	int			type;
	t_cmdlist	*list;

	list = 0;
	index = 0;
	type = -1;
	line = jump_space(line);
	strings_bzero(buf, 1, STR_I);
	while (line[index])
	{
		tmp = parse(&list, buf, line, &index);
		if (!tmp)
			return (ft_cmdclear(&list, free));
		if (tmp == line)
		{
			if (line[index] == '$')
				type = TENV;
			buf[GET_STR_I(index)][GET_CHR_I(index)] = line[index];
			index++;
		}
		line = tmp;
	}
	if (buf[0][0])
		end_block(&list, buf, type, index);
/*
	t_cmdlist	*tmp_list;

	tmp_list = list;
	printf("-----------------\n");
	while (tmp_list)
	{
		printf("cmd: %s | type: ", tmp_list->cmd);
		if (tmp_list->type == TSTRING)
			printf("TSTRING");
		else if (tmp_list->type == TCOMMAND)
			printf("TCOMMAND");
		else
			printf("TENV");
		printf(" | piece: %s\n", !tmp_list->piece? "no": "yes");
		tmp_list = tmp_list->next;
	}
	printf("----------------------\n");
*/
	return (list);
}

static char	
	*parse(t_cmdlist **list, char buf[STR_I][CHR_I], char *line, int *index)
{
	if (line[*index] == '"' || line[*index] == '\'')
	{
		if (*index && line[*index - 1] != ' ')
		{
			ft_cmdadd_back(list, ft_cmdnew(strings_join(buf, STR_I), TENV, 1));
			strings_bzero(buf, 1, STR_I);
			line += *index;
			*index = 0;
		}
		line = parse_quote(list, buf, line, *index);
	}
	else if (!(GET_CHR_I(*index + 1)) || (is_endcmd(line[*index]) && *index))
		line = buf_over(list, buf, line, *index);
	else if (is_endcmd(*line) && *line != ' ')
		line = parse_bop(list, buf, line, *index);
	else
		return (line);
	*index = 0;
	return (line);
}

static void
	end_block(t_cmdlist **list, char buf[STR_I][CHR_I], int type, int index)
{
	buf[GET_STR_I(index)][GET_CHR_I(index)] = 0;
	if (type == TENV)
		ft_cmdadd_back(list, ft_cmdnew(strings_join(buf, STR_I), TENV, 0));
	else if (check_built_op(buf[GET_STR_I(index)]))
		ft_cmdadd_back(list, ft_cmdnew(strings_join(buf, STR_I), TCOMMAND, 0));
	else
		ft_cmdadd_back(list, ft_cmdnew(strings_join(buf, STR_I), TSTRING, 0));
}

char	*jump_space(char *str)
{
	if (!str)
		return (NULL);
	while (*str == ' ')
		str++;
	return (str);
}

int	is_endcmd(char c)
{
	return (c == ' ' || c == '<' || c == '>' || c == '|');
}
