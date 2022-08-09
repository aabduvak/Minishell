/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 03:16:44 by aabduvak          #+#    #+#             */
/*   Updated: 2022/08/09 14:04:17 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	delete_node(t_envp **head_ref, char *name)
{
	t_envp	*temp;
	t_envp	*prev;

	temp = *head_ref;
	if (temp != NULL && !ft_strcmp(temp->key, name))
	{
		*head_ref = temp->next;
		ft_envpclear(temp);
		return ;
	}
	while (temp != NULL && ft_strcmp(temp->key, name))
	{
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL)
		return ;
	prev->next = temp->next;
	ft_envpclear(temp);
}

void	unset(t_process *process)
{
	t_envp	*envp;
	int		i;
	char	*key;
	char	**keys;

	i = 0;
	envp = process->envp;
	if (contains_char(process->args[0], '='))
	{
		keys = ft_split(process->args[0], '=');
		delete_node(&envp, keys[0]);
		free_list(keys);
		return ;
	}
	while (process->args[i])
	{
		key = process->args[i++];
		delete_node(&envp, key);
	}
}
