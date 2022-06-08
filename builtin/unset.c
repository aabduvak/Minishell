/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 03:16:44 by aabduvak          #+#    #+#             */
/*   Updated: 2022/06/08 17:13:41 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	helper(t_list	*lst, t_process *process, int i)
{
	char	**str;
	char	**envp_name;
	t_list	*tmp;

	while (lst)
	{
		if (contains_char((char *) lst->content, '='))
		{
			str = ft_split((char *) lst->content, '=');
			envp_name = ft_split(process->args[i], '=');
		}
		else
		{
			if (contains_char((char *) process->args[i], '='))
				envp_name = ft_split(process->args[i], '=');
			else
				envp_name = ft_split(process->args[i], ' ');
			str = ft_split((char *) lst->content, ' ');
		}
		if (!ft_strcmp(str[0], envp_name[0]))
		{
			tmp->next = lst->next;
			ft_lstdelone(lst, free);
		}
		tmp = lst;
		lst = lst->next;
		free_list(str);
		free_list(envp_name);
	}
}

void	unset(t_process *process)
{
	t_list	*lst;
	int		i;

	i = -1;
	lst = process->envp;
	while (process->args[++i])
	{
		helper(lst, process, i);
	}
}
