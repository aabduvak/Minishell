/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 07:38:51 by aabduvak          #+#    #+#             */
/*   Updated: 2022/08/03 10:38:26 by arelmas          ###   ########.fr       */
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
		//printf("parsing...\n");
		cmd = parse_line(line);
		//printf("parsed.\n");
	//	free(line);
		if (!cmd)
			continue ;
		//printf("env detecting...\n");
		parse_env(cmd, envl);
		//printf("end...\n");
		tmp = cmd;
		//printf("converting...\n");
		proc = convert(tmp, envl);
		//printf("converted\n");
		//ft_cmdclear(&tmp, free);
		if (!proc)
		{
			printf("Minishell: syntax error near unexpected token `|'\n");
			continue ;
		}
		proc->envp = envl;
		new_proc = proc;
		//printf("starting...\n");
		err = start_process(new_proc);
		//waitpid(0, &status, 0);
		//if (!err)
	//		ft_update_status(status % 255, proc);
		(void)status;
		while (new_proc)
		{
			wait(0);
			new_proc = new_proc->next;
		}
	//	ft_proclear(&proc, free);
	}
//	ft_envpclear(envl);
	return (0);
}
