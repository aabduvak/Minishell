/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 02:53:08 by aabduvak          #+#    #+#             */
/*   Updated: 2022/06/08 07:03:33 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	env(t_process *process)
{
	t_list	*lst;

	if (!process)
		return ;
	lst = process->envp;
	while (lst)
	{
		if (contains_char(lst->content, '='))
			ft_printf(process->stdfd->_stdout, "%s\n", (char *) lst->content);
		lst = lst->next;
	}
}
