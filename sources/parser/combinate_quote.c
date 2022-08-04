/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combinate_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:57:21 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/04 07:38:16 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_cmdlist	*combinate_quote(t_cmdlist *cmd)
{
	char		*join;
	char		*tmp;
	t_cmdlist	*res;
	t_cmdlist	*tmp_res;

	res = 0;
	while (cmd)
	{
		tmp_res = cmd;
		join = cmd->cmd;
		while (cmd && cmd->piece)
		{
			tmp = join;
			if (cmd->next)
			{
				join = ft_strjoin(tmp, cmd->next->cmd);
				free(tmp);
			}
			cmd = cmd->next;
		}
		cmd = cmd->next;
		ft_cmdadd_back(&res, ft_cmdnew(join, tmp_res->type, tmp_res->piece));
	}
	return (res);
}
