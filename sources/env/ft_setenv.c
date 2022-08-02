/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:42:09 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/02 03:37:19 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_setenv(t_process *process)
{
	t_envp	*tmp;
	char	**key;

	if (!process || !process->args)
		return ;
	key = ft_split(process->args[1], '=');
	if (!check_env(key[0]))
	{
		printf("export: not an identifier: %s\n", key[0]);
		free_list(key);
		return ;
	}
	unset(process);
	ft_envpadd_back(&process->envp, (t_envp *)ft_envpnew(process->args[1]));
	tmp = process->envp;
	while (tmp->next)
		tmp = tmp->next;
}
