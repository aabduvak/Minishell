/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:22:38 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/05 02:54:00 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	parse_env(t_cmdlist *list, t_envp *envl)
{
	char	*parsed;

	while (list)
	{
		if (list->type == TENV)
		{
			parsed = parse_cmd(list->cmd, envl);
			free(list->cmd);
			list->cmd = parsed;
			list->type = TSTRING;
		}
		list = list->next;
	}
}
