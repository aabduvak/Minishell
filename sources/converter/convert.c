/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 02:45:51 by arelmas           #+#    #+#             */
/*   Updated: 2022/07/08 15:52:23 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_process	*convert(t_cmdlist *list, t_envp *envl)
{
	t_cmdlist	*tmp;
	t_process	*process;

	if (!process)
		return (NULL);
	process = 0;
	while (list)
	{
		if (ft_procadd_back(&process, ft_procnew(list)))
			return (NULL);
		while (list && ft_strcmp(list->cmd) && list->type != TCOMMAND)
			list = list->next;
	}
	return (process);
}
