/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 01:16:43 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/04 01:27:15 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char
*ft_rdwrite(t_cmdlist **list, char buf[STR_I][CHR_I], char *line, int index);
static char
*ft_rdread(t_cmdlist **list, char buf[STR_I][CHR_I], char *line, int index);
static char
*ft_rdpipe(t_cmdlist **list, char buf[STR_I][CHR_I], char *line, int index);

char
	*parse_bop(t_cmdlist **list, char buf[STR_I][CHR_I], char *line, int index)
{
	buf[GET_STR_I(index)][GET_CHR_I(index)] = line[index];
	if (line[index] == '>')
		return (ft_rdwrite(list, buf, line, index));
	else if (line[index] == '<')
		return (ft_rdread(list, buf, line, index));
	else if (line[index] == '|')
		return (ft_rdpipe(list, buf, line, index));
	return (line);
}

static char
	*ft_rdwrite(t_cmdlist **list, char buf[STR_I][CHR_I], char *line, int index)
{
	if (line[index + 1] == '>')
	{
		buf[GET_STR_I(index)][GET_CHR_I(index) + 1] = line[index + 1];
		buf[GET_STR_I(index)][GET_CHR_I(index) + 2] = 0;
		line++;
	}
	else
		buf[GET_STR_I(index)][GET_CHR_I(index) + 1] = 0;
	line++;
	line = jump_space(line + index);
	ft_cmdadd_back(list, ft_cmdnew(strings_join(buf, STR_I), TCOMMAND, 0));
	strings_bzero(buf, 1, STR_I);
	return (line);
}

static char
	*ft_rdread(t_cmdlist **list, char buf[STR_I][CHR_I], char *line, int index)
{
	if (line[index + 1] == '<')
	{
		buf[GET_STR_I(index)][GET_CHR_I(index) + 1] = line[index + 1];
		buf[GET_STR_I(index)][GET_CHR_I(index) + 2] = 0;
		line++;
	}
	else
		buf[GET_STR_I(index)][GET_CHR_I(index) + 1] = 0;
	line++;
	line = jump_space(line + index);
	ft_cmdadd_back(list, ft_cmdnew(strings_join(buf, STR_I), TCOMMAND, 0));
	strings_bzero(buf, 1, STR_I);
	return (line);
}

static char
	*ft_rdpipe(t_cmdlist **list, char buf[STR_I][CHR_I], char *line, int index)
{
	buf[GET_STR_I(index)][GET_CHR_I(index) + 1] = 0;
	ft_cmdadd_back(list, ft_cmdnew(strings_join(buf, STR_I), TCOMMAND, 0));
	line++;
	line = jump_space(line + index);
	strings_bzero(buf, 1, STR_I);
	return (line);
}
