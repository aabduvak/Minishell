/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rdread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 02:45:03 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/05 02:45:37 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char
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
