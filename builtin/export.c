/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 02:44:38 by aabduvak          #+#    #+#             */
/*   Updated: 2022/06/08 05:50:15 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	contains_char(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (FT_TRUE);
		str++;
	}
	return (FT_FALSE);
}

void	export(t_process *process)
{
	char	**arr;
	t_list	*tmp;

	if (!process->args)
	{
		tmp = process->envp;
		while (tmp)
		{
			printf("declare -x %s\n", (char *) tmp->content);
			tmp = tmp->next;
		}
		return ;
	}
	if (contains_char(process->args[0], '='))
	{
		arr = ft_split(process->args[0], '=');
		if (arr[1])
			ft_setenv(arr[0], arr[1], process->envp);
		else
			ft_lstadd_back(&process->envp, ft_lstnew(process->args[0]));
		free_list(arr);
	}
	else
		ft_lstadd_back(&process->envp, ft_lstnew(process->args[0]));
}
