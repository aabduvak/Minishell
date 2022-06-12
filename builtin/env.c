/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 02:53:08 by aabduvak          #+#    #+#             */
/*   Updated: 2022/06/11 21:13:27 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	env(t_process *process)
{
	t_envp	*lst;

	if (!process)
		return ;
	lst = process->envp;
	while (lst)
	{
		if (contains_char(lst->fullstr, '='))
			ft_printf(process->stdfd->_stdout, "%s\n", (char *) lst->fullstr);
		lst = lst->next;
	}
}
