/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 03:16:44 by aabduvak          #+#    #+#             */
/*   Updated: 2022/06/11 21:11:21 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	unset(t_process *process)
{
	t_envp	*envp;
	t_envp	*tmp;
	int		i;

	i = -1;
	envp = process->envp;
	while (process->args[++i])
	{
		while (envp)
		{
			if (!ft_strcmp(process->args[0], envp->key))
			{
				tmp->next = envp->next;
				ft_envpdelone(envp, free);
			}
			tmp = envp;
			envp = envp->next;
		}
	}
}
