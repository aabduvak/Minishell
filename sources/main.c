/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 07:38:51 by aabduvak          #+#    #+#             */
/*   Updated: 2022/08/01 20:54:14 by arelmas          ###   ########.fr       */
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
	int			status;
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
	//	free(line);
		if (!cmd)
		{
			perror("Parse error");
			continue ;
		}
		parse_env(cmd, envl);
		tmp = cmd;
		proc = convert(tmp, envl);
		//ft_cmdclear(&tmp, free);
		if (!proc)
		{
			printf("Minishell: syntax error near unexpected token `|'\n");
			continue ;
		}
		proc->envp = envl;
		new_proc = proc;
		err = start_process(new_proc);
		waitpid(0, &status, 0);
		if (!err)
			ft_update_status(status % 255, proc);
	//	ft_proclear(&proc, free);
	}
//	ft_envpclear(envl);
	return (0);
}
