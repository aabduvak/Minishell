/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 03:16:44 by aabduvak          #+#    #+#             */
/*   Updated: 2022/07/31 17:22:51 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	unset(t_process *process)
{
	t_envp	*envp;
	t_envp	*tmp;
	int		i;
	char	**key;

	i = -1;
	key = ft_split(process->args[1], '=');
	envp = process->envp;
	while (process->args[++i])
	{
		while (envp)
		{
			if (!ft_strcmp(key[0], envp->key))
			{
				tmp->next = envp->next;
				ft_envpdelone(envp, free);
			}
			tmp = envp;
			envp = envp->next;
		}
	}
	i = 0;
	while (key[i])
		free(key[i++]);
	free(key);
}
