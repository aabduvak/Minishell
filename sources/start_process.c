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
		printf("process: %s\n", process->name);
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
		//close(process->stdfd->_stdout);
		//close(1);
		//close(process->stdfd->_stdin);
		//close(0);
		exit(0);
	}
	else
	{
		printf("process: %s | stdin: %i | stdout: %i\n", process->name, process->stdfd->_stdin, process->stdfd->_stdout);
		waitpid(child, &status, 0);
		printf("process << %s >> completed\n", process->name);
	}
	return (0);
}

static int	initfd(t_process *process, int	pipes[2])
{
	int	result;
	int	_stdout = 15;

	dup2(1, _stdout);
	printf("%p | %p\n", process->prev, process->next);
	result = redirect(process);
	if (result)
		return (result);
	printf("%s: hala1: %i\n", process->name, process->stdfd->_stdout);
	if (process->prev && !(process->redirect->type & DELIMETER & READ) && printf("%s: ok\n", process->name) && dup2(process->prev->stdfd->_stdin, 0) == -1)
			return (ERROR);
	//if (process->prev)
	//	close(process->prev->stdfd->_stdin);
	printf("%s: hala2\n", process->name);
	if (!process->prev && process->next && !(process->redirect->type & WRITE & OVERWRITE) && dup2(process->stdfd->_stdout, 1) == -1)
		return (ERROR);
	printf("%s: hala3\n", process->name);
	//if (process->prev && process->prev->redirect->type & WRITE & OVERWRITE)
	//	close(0);
	printf("%s: hala4\n", process->name);
	return (result);
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
		fd = open(process->redirect->name, O_CREAT | O_APPEND | O_WRONLY, 644 );
		if (fd < 0 || dup2(fd, 1))
			return (ERROR);
	}
	return (0);
}
