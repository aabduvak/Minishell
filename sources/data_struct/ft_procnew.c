/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_procnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:15:45 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/03 04:57:32 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void
	ft_setname(t_process *proc, char *src, t_envp *envl);
static char
	*ft_setpath_env(t_envp *envl, char *name);
static t_cmdlist
	*ft_setargs(t_process *proc, t_cmdlist *cmd);
static void
	*ft_setredirect(t_process *proc, t_cmdlist *cmd);

t_process	*ft_procnew(t_cmdlist *cmd, t_envp *envl)
{
	t_process	*process;

	if (!cmd)
		return (NULL);
	process = (t_process *)malloc(sizeof(t_process));
	ft_procinit(process, envl);
	ft_setname(process, cmd->cmd, envl);
	if (!ft_setargs(process, cmd))
	{
		free(process->name);
		free(process->path);
		free(process);
		return (NULL);
	}
	if (!ft_setredirect(process, cmd))
	{
		free(process->name);
		free(process->path);
		free_list(process->args);
		free(process);
		printf("Minishell: syntax error near unexpected token `newline'\n");
		return (NULL);
	}
	return (process);
}

static void
	ft_setname(t_process *proc, char *src, t_envp *envl)
{
	char	*name;

	if (!src)
		return ;
	name = ft_strrchr(src, '/');
	if (!name)
	{
		proc->name = ft_strdup(src);
		proc->path = ft_setpath_env(envl, src);
		return ;
	}
	proc->name = ft_strdup(name);
	proc->path = ft_strdup(src);
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
	while (tmp_cmd && tmp_cmd->type == TSTRING)
	{
		arg_len++;
		tmp_cmd = tmp_cmd->next;
	}
	args = (char **)malloc(sizeof(char *) * (arg_len + 1));
	if (!args)
		return (NULL);
	args[arg_len] = NULL;
	idx = 0;
	tmp_cmd = cmd;
	while (cmd && cmd->type == TSTRING)
	{
		args[idx++] = ft_strdup(cmd->cmd);
		cmd = cmd->next;
	}
	proc->args = args;
	return (tmp_cmd);
}

static void
	*ft_setredirect(t_process *proc, t_cmdlist *cmd)
{
	if (!cmd)
		return (NULL);
	while (cmd && ft_strcmp(cmd->cmd, "|"))
	{
		if (cmd->type == TCOMMAND && cmd->next && cmd->next->type == TSTRING)
		{
			if (!ft_strcmp(cmd->cmd, ">") && cmd->next)
			{
				close(open(cmd->next->cmd, O_CREAT, 0644));
				proc->redirect->write = ft_strdup(cmd->next->cmd);
			}
			else if (!ft_strcmp(cmd->cmd, ">>") && cmd->next)
			{
				close(open(cmd->next->cmd, O_CREAT, 0644));
				proc->redirect->overwrite = ft_strdup(cmd->next->cmd);
			}
			else if (!ft_strcmp(cmd->cmd, "<") && cmd->next)
				proc->redirect->read = ft_strdup(cmd->next->cmd);
			else if (!ft_strcmp(cmd->cmd, "<<") && cmd->next)
				proc->redirect->delimeter = ft_strdup(cmd->next->cmd);
		}
		else if (cmd->type == TCOMMAND)
			return (NULL);
		cmd = cmd->next;
	}
	return (proc);
}
