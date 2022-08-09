/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 09:51:02 by aabduvak          #+#    #+#             */
/*   Updated: 2022/08/09 13:14:59 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	child(t_process *process, int pipes[2])
{
	int	error;

	error = initfd(process, pipes);
	if (error)
		return (error);
	if (exec_builtin(process))
		exit(0);
	if (process->path && execve(process->path, process->args,
			deconstruct(process->envp)) == -1)
	{
		close(pipes[0]);
		close(pipes[1]);
		return (ER_EXEC);
	}
	exit(0);
}

void	parent(t_process *process)
{
	close(process->stdfd->_stdout);
	if (process->prev)
		close(process->prev->stdfd->_stdin);
}

void	set_stdfd(t_process *process, int pipes[2])
{
	process->stdfd->_stdin = -1;
	process->stdfd->_stdout = -1;
	if (process->next)
	{
		process->stdfd->_stdin = pipes[0];
		process->stdfd->_stdout = pipes[1];
	}
}
