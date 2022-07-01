/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 03:16:32 by arelmas           #+#    #+#             */
/*   Updated: 2022/06/23 14:40:07 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_setenv(t_process *process)
{
	if (!process || !process->args)
		return ;
	unset(process);
	ft_envpadd_back(&process->envp, (t_envp *)ft_envpnew(process->args[0]));
}
