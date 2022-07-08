/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_over.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:48:42 by arelmas           #+#    #+#             */
/*   Updated: 2022/07/08 02:26:43 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char
	*buf_over(t_cmdlist **list, char buf[STR_I][CHR_I], char *line, int index)
{
	buf[GET_STR_I(index)][GET_CHR_I(index)] = 0;
	if (GET_STR_I(index) == STR_I - 1 || (is_endcmd(line[index]) && index))
	{
		ft_cmdadd_back(list, ft_cmdnew(strings_join(buf, STR_I), TSTRING));
		strings_bzero(buf, 1, STR_I);
		return (jump_space(line + index));
	}
	return (line);
}
