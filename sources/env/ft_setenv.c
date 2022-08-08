/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:42:09 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/08 16:01:14 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_setenv(t_process *process)
{
	char	**key;

	if (!process || !process->args)
		return ;
	key = ft_split(process->args[0], '=');
	if (!check_env(key[0]))
	{
		printf("export: not an identifier: %s\n", key[0]);
		free_list(key);
		return ;
	}
	unset(process);
	ft_envpadd_back(&process->envp, (t_envp *)ft_envpnew(process->args[0]));
}

/* free_list(key) */