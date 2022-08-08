/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rdpipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 02:42:12 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/08 17:01:56 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char
	*ft_rdpipe(t_cmdlist **list, char buf[STR_I][CHR_I], char *line, int index)
{
	buf[ft_get_stri(index)][ft_get_chri(index) + 1] = 0;
	ft_cmdadd_back(list, ft_cmdnew(strings_join(buf, STR_I), TCOMMAND, 0));
	line++;
	line = jump_space(line + index);
	strings_bzero(buf, 1, STR_I);
	return (line);
}
