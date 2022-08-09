/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 07:38:51 by aabduvak          #+#    #+#             */
/*   Updated: 2022/08/09 13:46:06 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void			close_process(t_process *proc);
static t_process	*init_proc(char *line, t_envp *envl);

static char	*get_inputstr(char *username, int ac, char **av)
{
	char		*line;

	(void)ac;
	(void)av;
	connectsignals();
	line = get_input(username);
	signal(SIGINT, nothing);
	if (!line)
		exit(0);
	return (line);
}

int	main(int argc, char **argv, char **envp)
{
	char		*line;
	t_process	*proc;
	t_envp		*envl;
	char		*username;

	envl = construct(envp);
	if (!envl)
		perror("Contruct error");
	username = ft_getenv("USER", envl);
	while (1)
	{
		line = get_inputstr(username, argc, argv);
		proc = init_proc(line, envl);
		if (!proc)
			continue ;
		start_process(proc);
		close_process(proc);
	}
	return (0);
}

static void	close_process(t_process *proc)
{
	int			status;
	t_process	*tmp;

	tmp = proc;
	while (proc)
	{
		wait(&status);
		ft_update_status(status % 255, proc);
		ft_update_envp("_", proc->path, proc->envp);
		proc = proc->next;
	}
	ft_proclear(&tmp, free);
}

static t_process	*init_proc(char *line, t_envp *envl)
{
	t_cmdlist	*cmd;
	t_cmdlist	*tmp;
	t_process	*proc;

	cmd = parse_line(line);
	free(line);
	if (!cmd)
		return (0);
	parse_env(cmd, envl);
	tmp = combinate_quote(cmd);
	ft_cmdclear(&cmd, free);
	proc = convert(tmp, envl);
	ft_cmdclear(&tmp, free);
	if (!proc)
		return (0);
	ft_cmdclear(&tmp, free);
	return (proc);
}
