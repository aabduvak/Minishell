/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 01:25:16 by arelmas           #+#    #+#             */
/*   Updated: 2022/06/08 08:53:23 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	cd(t_process *process)
{
	if (!process->args)
	{
		if (chdir(ft_getenv("HOME", process->envp)))
			perror("cd");
	}
	else if (process->args[0][0] == '~')
	{
		if (chdir(ft_getenv("HOME", process->envp)))
			perror("cd");
		if (chdir(process->args[0] + 2))
			perror("cd");
	}
	else if (chdir(process->args[0]) == -1)
		perror("cd");
}
