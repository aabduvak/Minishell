/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 07:38:51 by aabduvak          #+#    #+#             */
/*   Updated: 2022/07/31 12:33:36 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*get_inputstr(void)
{
	char		*line;

	line = get_input();
	if (!line)
		exit(0);
	return (line);
}

int	main(int argc, char **argv, char **envp)
{
	int			err;
	char		*line;
	t_cmdlist	*cmd;
	t_cmdlist	*tmp;
	t_envp		*envl;
	t_process	*proc;
	t_process	*new_proc;

	(void)argc;
	(void)argv;
	connectsignals();
	envl = construct(envp);
	if (!envl)
		perror("Contruct error");
	while (1)
	{
		line = get_inputstr();
		cmd = parse_line(line);
		if (!cmd)
		{
			perror("Parse error");
			continue ;
		}
		tmp = cmd;
		proc = convert(tmp, envl);
		proc->envp = envl;
		ft_cmdclear(&tmp, free);
		if (!proc)
		{
			perror("Convertation error");
			continue ;
		}
		new_proc = proc;
		err = start_process(new_proc);
		wait(0);
		waitpid(0, &err, 0);
		if (!err)
		{
			printf("----evet------\n");
			ft_update_status(err % 255, proc);
		}
		ft_proclear(&proc, free);
	}
	ft_envpclear(envl);
	return (0);
}
