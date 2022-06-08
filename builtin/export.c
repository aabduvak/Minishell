/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 02:44:38 by aabduvak          #+#    #+#             */
/*   Updated: 2022/06/08 16:09:29 by aabduvak         ###   ########.fr       */
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
	t_list	*tmp;

	if (!process->args)
	{
		tmp = process->envp;
		while (tmp)
		{
			ft_printf(process->stdfd->_stdout,
				"declare -x %s\n", (char *) tmp->content);
			tmp = tmp->next;
		}
		return ;
	}
	ft_setenv(process);
}
