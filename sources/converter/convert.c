/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 02:45:51 by arelmas           #+#    #+#             */
/*   Updated: 2022/07/29 10:02:11 by arelmas          ###   ########.fr       */
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
		if (!ft_procadd_back(&process, new_proc))
			return (NULL);
		while (list && !(!ft_strcmp(list->cmd, "|") && list->type == TCOMMAND))
				list = list->next;
		if (list && !ft_strcmp(list->cmd, "|") && list->type == TCOMMAND)
			list = list->next;
	}
	return (process);
}
