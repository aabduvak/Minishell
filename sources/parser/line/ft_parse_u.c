/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 03:22:17 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/05 10:47:12 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char
	*is_quote(t_parser *data, char buf[STR_I][CHR_I], char *line, int *index);
static char
	*is_end(t_parser *data, char buf[STR_I][CHR_I], char *line, int *index);

char
	*ft_parse_u(t_parser *data, char buf[STR_I][CHR_I], char *line, int *index)
{
	if (line[*index] == '"' || line[*index] == '\'')
		line = is_quote(data, buf, line, index);
	else if (!(GET_CHR_I(*index + 1)) || (is_endcmd(line[*index]) && *index))
	{
		buf[GET_STR_I(*index)][GET_CHR_I(*index)] = 0;
		if (GET_STR_I(*index) == STR_I - 1
			|| (is_endcmd(line[*index]) && *index))
			line = is_end(data, buf, line, index);
	}
	else if (is_endcmd(*line) && *line != ' ')
	{
		line = parse_bop(&data->list, buf, line, *index);
	}
	else
	{
		return (line);
	}
	*index = 0;
	return (line);
}

static char
	*is_quote(t_cmdlist **list, char buf[STR_I][CHR_I], char *line, int *index)
{
	if (*index && line[*index - 1] != ' ')
	{
		ft_cmdadd_back(list, ft_cmdnew(strings_join(buf, STR_I),
				TENV, 1));
		strings_bzero(buf, 1, STR_I);
		line += *index;
		*index = 0;
	}
	return (parse_quote(data->list, buf, line, *index));
}

static char
	*is_end(t_parser *data, char buf[STR_I][CHR_I], char *line, int *index)
{
	if (data->type == TENV)
		ft_cmdadd_back(data->list,
			ft_cmdnew(strings_join(buf, STR_I), TENV, 0));
	else
		ft_cmdadd_back(data->list,
			ft_cmdnew(strings_join(buf, STR_I), TSTRING, 0));
	strings_bzero(buf, 1, STR_I);
	return (jump_space(line + *index));
}
