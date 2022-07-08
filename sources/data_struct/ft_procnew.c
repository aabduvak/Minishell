/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_procnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:15:45 by arelmas           #+#    #+#             */
/*   Updated: 2022/07/08 15:45:06 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <data_struct.h>

static void
	ft_setname(t_process *proc, char *src, t_envp *envl);
static char
	*ft_setpath_env(t_envp *envl, char *name);
static int
	ft_setargs(t_process *proc, t_cmdlist *cmd);

t_process	*ft_procnew(t_cmdlist *cmd)
{
	t_process	*process;

	if (!cmd)
		return (NULL);
	process = (t_process *)malloc(sizeof(t_process));
	ft_procinit(process);
	ft_setname(process, cmd->cmd);
	if (!ft_setargs(process, cmd))
	{
		free(process->name);
		free(process->path);
		free(process);
	}
	if (!ft_setredirect(process, cmd))
	{
		free(process->name);
		free(process->path);
		free_list(process->args);
		free(process);
	}
	process->next = NULL;
	process->prev = NULL;
	return (process);
}

static void
	ft_setname(t_process *proc, char *src, t_envp *envl)
{
	char	*name;

	if (!src)
		return (NULL);
	name = ft_strrchr(dst, '/');
	if (!name)
	{
		proc->name = ft_strdup(src);
		proc->path = ft_setpath(envl, src);
		return ;
	}
	proc->name = ft_strdup(name);
	proc->path = ft_substr(src, 0, name - src);
}

static char
	*ft_setpath_env(t_envp *envl, char *name)
{
	char	*path;

	path = ft_getenv("PATH", envl);
	return (get_fullpath(path, name));
}

static t_cmdlist
	*ft_setargs(t_process *proc, t_cmdlist *cmd)
{
	int			idx;
	int			arg_len;
	char		**args;
	t_cmdlist	*tmp_cmd;

	arg_len = 0;
	tmp_cmd = cmd;
	while (tmp_cmd->type == TSTRING)
	{
		arg_len++;
		tmp_cmd = tmp_cmd->next;
	}
	args = (char **)malloc(sizeof(char *) * (arg_len + 2));
	if (!args)
		return (NULL);
	*args = ft_strdup(proc->name);
	args[arg_len + 1] = NULL;
	idx = 1;
	while (cmd->type == TSTRING)
	{
		args[idx] = ft_strdup(cmd->cmd);
		cmd = cmd->next;
	}
	proc->args = args;
	return (cmd);
}

static void
	ft_check_redirect(t_process *proc, t_cmdlist *cmd)
{
	if (!cmd)
		return ;
	while (cmd && ft_strcmp(cmd->cmd, "|"))
	{
		if (cmd->type == TCOMMAND && cmd->next && cmd->next->type == TSTRING)
		{
			if (!ft_strcmp(cmd->cmd, ">"))
				proc->write = ft_strdup(cmd->next->cmd);
			else if (!ft_strcmp(cmd->cmd, ">>"))
				proc->overwrite = ft_strdup(cmd->next->cmd);
			else if (!ft_strcmp(cmd->cmd, "<"))
				proc->read = ft_strdup(cmd->next->cmd);
			else if (!ft_strcmp(cmd->cmd, "<<"))
				proc->delimeter = ft_strdup(cmd->next->cmd);
		}
		else
			return (NULL);
		cmd = cmd->next->next;
	}
	return (proc);
}
