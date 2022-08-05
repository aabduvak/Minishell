/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_block.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 03:23:05 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/05 04:20:59 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void
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
