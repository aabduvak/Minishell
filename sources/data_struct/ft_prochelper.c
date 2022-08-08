/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prochelper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 22:05:00 by aabduvak          #+#    #+#             */
/*   Updated: 2022/08/09 01:04:14 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	ft_readredirect(t_process *proc, t_cmdlist *cmd)
{
	close(open(cmd->next->cmd, O_CREAT, 0644));
	ft_write_restart(proc, &proc->redirect->write, cmd->next->cmd);
}

static void	ft_overrideredirect(t_process *proc, t_cmdlist *cmd)
{
	close(open(cmd->next->cmd, O_CREAT, 0644));
	ft_write_restart(proc, &proc->redirect->overwrite, cmd->next->cmd);
}

static void	ft_delimeterredirect(t_process *proc, t_cmdlist *cmd)
{
	if (proc->redirect->read)
	{
		free(proc->redirect->read);
		proc->redirect->read = 0;
	}
	ft_lstadd_back(&proc->redirect->delimeter,
		ft_lstnew(ft_strdup(cmd->next->cmd)));
}

static int	ft_otherredirect(t_process *proc, t_cmdlist *cmd)
{
	char	*tmp;
	char	*buf;
	char	*f_path;

	buf = getcwd(0, 0);
	tmp = ft_strjoin(buf, "/");
	f_path = ft_strjoin(tmp, cmd->next->cmd);
	if (access(f_path, F_OK))
	{
		printf("minishell: no such file or directory: %s\n",
			cmd->next->cmd);
		free(f_path);
		return (0);
	}
	else
		ft_read_restart(proc, &proc->redirect->read,
			cmd->next->cmd);
	free(tmp);
	free(buf);
	free(f_path);
	return (1);
}

int	ft_procherlper(t_process *proc, t_cmdlist *cmd)
{
	if (!ft_strcmp(cmd->cmd, ">") && cmd->next)
		ft_readredirect(proc, cmd);
	else if (!ft_strcmp(cmd->cmd, ">>") && cmd->next)
		ft_overrideredirect(proc, cmd);
	else if (!ft_strcmp(cmd->cmd, "<") && cmd->next)
	{
		if (!ft_otherredirect(proc, cmd))
			return (0);
	}
	else if (!ft_strcmp(cmd->cmd, "<<") && cmd->next)
		ft_delimeterredirect(proc, cmd);
	return (1);
}
