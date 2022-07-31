/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 02:44:38 by aabduvak          #+#    #+#             */
/*   Updated: 2022/07/31 06:04:37 by aabduvak         ###   ########.fr       */
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
	t_envp	*tmp;

	if (!process->args)
	{
		tmp = process->envp;
		while (tmp)
		{
			if (tmp->fullstr[0] != '?')
				printf("declare -x %s\n", (char *) tmp->fullstr);
			tmp = tmp->next;
		}
		return ;
	}
	ft_setenv(process);
}
