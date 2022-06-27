/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:56:49 by arelmas           #+#    #+#             */
/*   Updated: 2022/06/24 15:08:11 by arelmas          ###   ########.fr       */
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
	int		status;
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
		if (execve(process->path, process->args, deconstruct(process->envp)) == -1)
			return (ER_EXEC);
		exit(0);
	}
	else
	{
		waitpid(child, &status, 0);
		close(pipes[1]);
	}
	return (0);
}

static int	initfd(t_process *process, int	pipes[2])
{
	int	result;
	int	_stdout = 15;

	result = redirect(process);
	if (result)
		return (result);
	if (process->prev && !(process->redirect->type & (DELIMETER | READ)) && dup2(process->prev->stdfd->_stdin, 0) == -1)
			return (ERROR);
	if (process->next && !(process->redirect->type & (WRITE | OVERWRITE)) && dup2(process->stdfd->_stdout, 1) == -1)
		return (ERROR);
	//if (process->prev && process->prev->redirect->type & (WRITE | OVERWRITE))
	//	close(0);
	return (result);
}

static int	redirect(t_process *process)
{
	int		fd;
	int		readed;
	char		buf[255];

	if (process->redirect->type == READ)
	{
		fd = open(process->redirect->name, O_RDONLY);
		if (fd < 0)
			return (ER_NOFILE);
		if (dup2(fd, 0) == -1)
			return (ERROR);
	}
	else if (process->redirect->type == WRITE)
	{
		fd = open(process->redirect->name, O_CREAT | O_TRUNC | O_WRONLY, 0644);
		if (fd < 0 || dup2(fd, 1) == -1)
			return (ERROR);
	}
	else if (process->redirect->type == DELIMETER)
	{
		readed = 1;
		while (readed > 1)
		{
			readed = read(0, buf, 255);
			buf[readed] = 0; 
			if (readed > 0)
				write(process->stdfd->_stdout, buf, readed);
		}
	}
	else if (process->redirect->type == OVERWRITE)
	{
		fd = open(process->redirect->name, O_CREAT | O_APPEND | O_WRONLY, 0644 );
		if (fd < 0 || dup2(fd, 1))
			return (ERROR);
	}
	return (0);
}
