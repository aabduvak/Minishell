/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_over.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:48:42 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/08 17:01:07 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char
	*buf_over(t_cmdlist **list, char buf[STR_I][CHR_I], char *line, int index)
{
	buf[ft_get_stri(index)][ft_get_chri(index)] = 0;
	if (ft_get_stri(index) == STR_I - 1 || (is_endcmd(line[index]) && index))
	{
		ft_cmdadd_back(list, ft_cmdnew(strings_join(buf, STR_I), TSTRING, 0));
		strings_bzero(buf, 1, STR_I);
		return (jump_space(line + index));
	}
	return (line);
}
