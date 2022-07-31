/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 07:38:51 by aabduvak          #+#    #+#             */
/*   Updated: 2022/07/31 03:52:11 by arelmas          ###   ########.fr       */
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
		//free(line);
		if (!cmd)
		{
			perror("Parse error");
			continue ;
		}
		tmp = cmd;
		proc = convert(tmp, envl);
		ft_cmdclear(&tmp, free);
		if (!proc)
		{
			perror("Convertation error");
			continue ;
		}
		new_proc = proc;
		err = start_process(new_proc);
		ft_proclear(&proc, free);
		if (err)
		{
			if (err == ER_PIPES)
				printf("Pipes error\n");
			else if (err == ER_EXEC)
				perror("Minishell");
			else if (err == ER_RUNPROC)
				perror("Minishell");
			else
				perror("Minishell");
			continue ;
		}
		wait(0);
	}
	ft_envpclear(envl);
	return (0);
}
