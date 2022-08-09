/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 03:19:49 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/09 05:24:38 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_process	*convert(t_cmdlist *list, t_envp *envl)
{
	t_process	*process;
	t_process	*new_proc;

	if (!list)
		return (NULL);
	process = 0;
	while (list)
	{
		new_proc = ft_procnew(list, envl);
		if (!new_proc)
			return (NULL);
		if (!ft_procadd_back(&process, new_proc))
			return (NULL);
		while (list && !(!ft_strcmp(list->cmd, "|") && list->type == TCOMMAND))
				list = list->next;
		if (list && !ft_strcmp(list->cmd, "|"))
		{
			if (!list->next || !ft_strcmp(list->next->cmd, "|"))
				return (0);
			if (list->type == TCOMMAND)
				list = list->next;
		}
	}
	return (process);
}
