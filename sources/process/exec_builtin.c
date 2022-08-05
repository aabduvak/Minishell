/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 02:38:20 by aabduvak          #+#    #+#             */
/*   Updated: 2022/08/05 02:39:30 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	exec_builtin(t_process *proc)
{
	int	key;

	key = 0;
	if (!ft_strcmp(proc->name, BT_CD) && ++key)
		cd(proc);
	else if (!ft_strcmp(proc->name, BT_ENV) && ++key)
		env(proc);
	else if (!ft_strcmp(proc->name, BT_UNSET) && ++key)
		unset(proc);
	else if (!ft_strcmp(proc->name, BT_ECHO) && ++key)
		echo(proc);
	else if (!ft_strcmp(proc->name, BT_PWD) && ++key)
		pwd(proc);
	else if (!ft_strcmp(proc->name, BT_EXPORT) && ++key)
		export(proc);
	else if (!ft_strcmp(proc->name, BT_EXIT) && ++key)
		ft_exit(proc);
	return (key);
}
