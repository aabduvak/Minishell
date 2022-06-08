/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 03:16:32 by arelmas           #+#    #+#             */
/*   Updated: 2022/06/08 16:57:39 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_setenv(t_process *process)
{
	if (!process || !process->args)
		return ;
	unset(process);
	ft_lstadd_back(&process->envp, ft_lstnew(process->args[0]));
}
