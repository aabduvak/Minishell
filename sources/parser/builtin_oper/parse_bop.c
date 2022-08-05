/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 01:16:43 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/05 02:47:27 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

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
