/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 01:16:43 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/08 17:01:56 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char
	*parse_bop(t_cmdlist **list, char buf[STR_I][CHR_I], char *line, int index)
{
	buf[ft_get_stri(index)][ft_get_chri(index)] = line[index];
	if (line[index] == '>')
		return (ft_rdwrite(list, buf, line, index));
	else if (line[index] == '<')
		return (ft_rdread(list, buf, line, index));
	else if (line[index] == '|')
		return (ft_rdpipe(list, buf, line, index));
	return (line);
}
