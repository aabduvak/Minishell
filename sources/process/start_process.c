/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 20:46:00 by arelmas           #+#    #+#             */
/*   Updated: 2022/07/31 02:23:52 by arelmas          ###   ########.fr       */
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
	printf("path: %s: %i\n", process->path, access(process->path, F_OK));
	while (process)
	{
		if (access(process->path, F_OK) || run(process))
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
	/*error = initfd(process, pipes);
	if (exec_builtin(process))
		return (0);
	*/
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
		//close(pipes[0]);
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
	if (process->prev && !process->redirect->read && !process->redirect->delimeter &&\
		dup2(process->prev->stdfd->_stdin, 0) == -1)
		return (ERROR);
	if (process->next && !process->redirect->write && !process->redirect->overwrite &&\
		dup2(process->stdfd->_stdout, 1) == -1)
		return (ERROR);
	if (process->prev && process->prev->redirect->write && process->prev->redirect->overwrite)
		close(0);
	return (result);
}

static int	redirect(t_process *process)
{
	if (process->redirect->read)
		return (red_read(process->redirect->read));
	else if (process->redirect->write)
		return (red_write(process->redirect->write));
	else if (process->redirect->delimeter)
		return (red_delimeter(process->redirect->delimeter));
	else if (process->redirect->overwrite)
		return (red_overwrite(process->redirect->overwrite));
	return (0);
}
