/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 07:38:51 by aabduvak          #+#    #+#             */
/*   Updated: 2022/07/31 02:25:49 by arelmas          ###   ########.fr       */
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
	t_cmdlist	*cmd;
	t_cmdlist	*tmp;
	t_envp		*envl;
	t_process	*proc;
	t_process	*new_proc;

	(void)argc;
	(void)argv;
	connectsignals();
	while (1)
	{
		cmd = parse_line(get_inputstr());
		if (!cmd)
		{
			perror("Parse error");
			continue ;
		}
		tmp = cmd;
		envl = construct(envp);
		if (!envl)
		{
			perror("Contruct error");
			continue ;
		}
		proc = convert(tmp, envl);
		if (!proc)
		{
			perror("Convertation error");
			continue ;
		}
		new_proc = proc;
		err = start_process(new_proc);
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
	return (0);
}
