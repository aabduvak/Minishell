/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 03:37:30 by aabduvak          #+#    #+#             */
/*   Updated: 2022/08/03 05:47:55 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	ft_printerr(t_process *proc, int status)
{
	char	*name;

	name = proc->name;
	if (!name)
		name = "minishell";
	if (status == ER_NOTPERMITTED)
		printf("%s: %s\n", name, E_NOTPERMITTED);
	else if (status == ER_EXEC)
		printf("%s: %s\n", name, E_EXEC);
	else if (status == ER_NOCOMM)
		printf("%s: %s\n", name, E_NOCOMM);
	else if (status == ER_NOPROC)
		printf("%s: %s\n", name, E_NOPROC);
	else if (status == ER_NOFILE)
		printf("minishell: %s: %s\n", E_NOFILE, proc->path);
	else if (status == ER_RUNPROC)
		printf("%s: %s\n", name, E_RUNPROC);
	else if (status == ER_ISDIR)
		printf("%s: %s\n", name, E_ISDIR);
	else if (status == ER_NOTDIR)
		printf("%s: %s\n", name, E_NOTDIR);
	else if (status == ER_PIPES)
		printf("%s: %s\n", name, E_PIPES);
	else if (status == ER_TIMEDOUT)
		printf("%s: %s\n", name, E_TIMEDOUT);
	else if (status == ER_CONNREFUSED)
		printf("%s: %s\n", name, E_CONNREFUSED);
}

void	ft_update_status(int status, t_process *process)
{
	t_envp	*envp;
	char	*tmp;

	envp = process->envp;
	while (envp)
	{
		if (!ft_strcmp("?", envp->key))
		{
			envp->value = ft_itoa(status);
			tmp = ft_strjoin(envp->key, "=");
			envp->fullstr = ft_strjoin(tmp, envp->value);
			break ;
		}
		envp = envp->next;
	}
}

int	ft_error(t_process *process, int status)
{
	if (!process)
		return (1);
	ft_printerr(process, status);
	ft_update_status(status, process);
	return (status);
}
