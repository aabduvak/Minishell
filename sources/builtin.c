/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:54:53 by aabduvak          #+#    #+#             */
/*   Updated: 2022/06/08 07:56:13 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include "../includes/structs.h"

int	is_builtin(char *command)
{
	if (ft_strcmp(command, BT_EXIT) == 0 || \
		ft_strcmp(command, BT_CD) == 0 || \
		ft_strcmp(command, BT_PWD) == 0 || \
		ft_strcmp(command, BT_UNSET) == 0 || \
		ft_strcmp(command, BT_ENV) == 0 || \
		ft_strcmp(command, BT_EXPORT) == 0 || \
		ft_strcmp(command, BT_ECHO) == 0)
		return (FT_TRUE);
	return (FT_FALSE);
}

void	run_builtin(t_process *process)
{
	if (ft_strcmp(process->name, BT_EXIT) == 0)
		return ;
	else if (ft_strcmp(process->name, BT_CD) == 0)
		return (cd(process));
	else if (ft_strcmp(process->name, BT_PWD) == 0)
		return (pwd(process));
	else if (ft_strcmp(process->name, BT_UNSET) == 0)
		return (unset(process));
	else if (ft_strcmp(process->name, BT_ENV) == 0)
		return (env(process));
	else if (ft_strcmp(process->name, BT_EXPORT) == 0)
		return (export(process));
	else
		return (echo(process));
}
	