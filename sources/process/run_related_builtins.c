/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_related_builtins.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 09:49:20 by aabduvak          #+#    #+#             */
/*   Updated: 2022/08/05 09:50:16 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	run_related_builtins(t_process *process, int pipes[2])
{
	close(pipes[0]);
	close(pipes[1]);
	if (!ft_strcmp(process->name, BT_CD))
		cd(process);
	else if (!ft_strcmp(process->name, BT_EXIT))
		ft_exit(process);
	else if (!ft_strcmp(process->name, BT_UNSET))
		unset(process);
	else
		export(process);
	return (0);
}
