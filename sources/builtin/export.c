/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 02:44:38 by aabduvak          #+#    #+#             */
/*   Updated: 2022/08/02 02:11:22 by aabduvak         ###   ########.fr       */
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

	if (process && !*(process->args + 1))
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
