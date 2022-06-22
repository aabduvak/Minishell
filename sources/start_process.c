/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:56:49 by arelmas           #+#    #+#             */
/*   Updated: 2022/06/23 00:34:59 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	start_process(t_process *process)
{
	if (!process)
		return (ER_NOPROC);
	while (process)
	{
		if (ft_run(process))
			return (ER_RUNPROC);
		process = process->next;
	}
}

static int	run(t_process *process)
{
	int		pipes[2];
	pid_t	child;

	if (pipe(pipes))
		return (ER_PIPES);
	process->stdfd->_stdin = pipes[0];
	process->stdfd->_stdout = pipes[1];
	child = fork();
	if (!child)
	{
		
	}
}

static int	initfd(t_process *process, int	pipes[])
{
	int	result;

	result = redirect(process);
	if (result)
		return (result);
	if (process->prev && !(process->redirect->type | OVERWRITE | READ) && dup2(process->prev->stdfd->_stdin, 0) == -1)
			return (ERROR);
	if (process->next && dup2(process->stdfd->_stdout, 1) == -1)
		return (ERROR);
	return (redirect(process));
}

static int	redirect(t_process *process)
{
	int		fd;
	int		readed;
	char	buf[255];
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
		fd = open(process->redirect->name, O_CREAT | O_TRUNC | O_WRONLY, 644);
		if (fd < 0 || dup2(fd, 1) == -1)
			return (ERROR);
	}
	else if (process->redirect->type == DELIMITER)
	{
		readed = 1;
		while (readed > 1)
		{
			readed = read(0, buf, 255);
			if (readed > 0)
				write(process->stdfd->_stdout, buf, readed);
		}
	}
	else if (process->redirect->type == OVERWRITE)
	{
		fd = open(process->redirect->name, O_CREAT | O_APPEND | O_WRONLY, 644 );
		if (fd < 0 || dup2(fd, 1))
			return (ERROR);
	}
	return (0);
}
