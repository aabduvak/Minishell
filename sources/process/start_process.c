/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 04:53:44 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/05 04:37:10 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	run(t_process *process);
static int	initfd(t_process *process, int pipes[2]);
static int	redirect(t_process *process);

int	start_process(t_process *process)
{
	int			ret;

	if (!process)
		return (ER_NOPROC);
	while (process)
	{
		ret = run(process);
		if (ret)
			return (ret);
		process = process->next;
	}
	return (0);
}
	/*
	while (tmp)
	{
		printf("closing: %i\n", tmp->stdfd->_stdin);
		printf("closing: %i\n\n", tmp->stdfd->_stdout);
		close(tmp->stdfd->_stdin);
		close(tmp->stdfd->_stdout);
		tmp = tmp->next;
	}*/

static void	run_builtin(t_process *process, int pipes[2])
{
	if (!process->next && !process->prev && \
	(!ft_strcmp(process->name, BT_CD) || \
	!ft_strcmp(process->name, BT_EXPORT) || \
	!ft_strcmp(process->name, BT_EXIT) || \
	!ft_strcmp(process->name, BT_UNSET)))
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
}

static int	run(t_process *process)
{
	int		error;
	int		nofile;
	int		pipes[2];

	pipes[0] = -1;
	pipes[1] = -1;
	process->stdfd->_stdin = -1;
	process->stdfd->_stdout = -1;
	nofile = proc_access(process->name);
	if (access(process->path, F_OK) && nofile)
	{
		if (!process->path)
			return (ft_error(process, ER_NOCOMM));
		return (ft_error(process, ER_NOFILE));
	}
	if (access(process->path, X_OK) && nofile)
		return (ft_error(process, ER_ACCES));
	if (process->next && pipe(pipes))
		return (ft_error(process, ER_PIPES));
	if (process->next)
	{
		process->stdfd->_stdin = pipes[0];
		process->stdfd->_stdout = pipes[1];
	}
	
	
	process->pid = fork();
	if (!process->pid)
	{
		error = initfd(process, pipes);
		if (error)
			return (error);
		if (exec_builtin(process))
			exit(0);
		if (execve(process->path, process->args,
				deconstruct(process->envp)) == -1)
		{
			close(pipes[0]);
			close(pipes[1]);
			return (ER_EXEC);
		}
		exit(0);
	}
	else
	{
		close(process->stdfd->_stdout);
		if (process->prev)
			close(process->prev->stdfd->_stdin);
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
	if (process->prev && \
		!process->redirect->read && !process->redirect->delimeter && \
		dup2(process->prev->stdfd->_stdin, 0) == -1)
		return (ERROR);
	if (process->next && \
		!process->redirect->write && !process->redirect->overwrite && \
		dup2(process->stdfd->_stdout, 1) == -1)
		return (ERROR);
	return (result);
}
	/* if (process->prev && process->prev->redirect->write && \ 
		process->prev->redirect->overwrite)
		close(0);
	if (!process->next)
		close(process->stdfd->_stdout); */

static int	redirect(t_process *process)
{	
	if (process->redirect->delimeter)
		red_delimeter(process->redirect->delimeter, !!process->redirect->read);
	if (process->redirect->read)
		red_read(process->redirect->read);
	if (process->redirect->write)
		red_write(process->redirect->write);
	if (process->redirect->overwrite)
		red_overwrite(process->redirect->overwrite);
	return (0);
}
