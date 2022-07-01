/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:56:49 by arelmas           #+#    #+#             */
/*   Updated: 2022/07/02 01:22:41 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	run(t_process *process);
static int	initfd(t_process *process, int pipes[2]);
static int	redirect(t_process *process);

int	start_process(t_process *process)
{
	if (!process)
		return (ER_NOPROC);
	while (process)
	{
		if (run(process))
			return (ER_RUNPROC);
		process = process->next;
	}
	return (0);
}

static int	run(t_process *process)
{
	int		error;
	int		pipes[2];
	pid_t	child;

	if (pipe(pipes))
		return (ER_PIPES);
	process->stdfd->_stdin = pipes[0];
	process->stdfd->_stdout = pipes[1];
	child = fork();
	if (!child)
	{
		error = initfd(process, pipes);
		if (error)
			return (error);
		if (execve(process->path, process->args,
				deconstruct(process->envp)) == -1)
			return (ER_EXEC);
		exit(0);
	}
	else
	{
		close(pipes[1]);
		close(pipes[0]);
	}
	return (0);
}

static int	initfd(t_process *process, int pipes[2])
{
	int	result;

	(void)pipes;
	result = redirect(process);
	if (result)
		return (result);
	if (process->prev && !(process->redirect->type & (DELIMETER | READ)) && \
		dup2(process->prev->stdfd->_stdin, 0) == -1)
		return (ERROR);
	if (process->next && !(process->redirect->type & (WRITE | OVERWRITE)) && \
		dup2(process->stdfd->_stdout, 1) == -1)
		return (ERROR);
	if (process->prev && process->prev->redirect->type & (WRITE | OVERWRITE))
		close(0);
	return (result);
}

static int	redirect(t_process *process)
{
	if (process->redirect->type == READ)
		return (red_read(process->redirect->name));
	else if (process->redirect->type == WRITE)
		return (red_write(process->redirect->name));
	else if (process->redirect->type == DELIMETER)
		return (red_delimeter(process->redirect->name));
	else if (process->redirect->type == OVERWRITE)
		return (red_overwrite(process->redirect->name));
	return (0);
}
