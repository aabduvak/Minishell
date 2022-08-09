/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 07:38:51 by aabduvak          #+#    #+#             */
/*   Updated: 2022/08/09 03:39:50 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <info.h>

t_envp *envl;

char	*get_inputstr(char *username)
{
	char		*line;

	line = get_input(username);
	if (!line)
		exit(0);
	return (line);
}

int	main(int argc, char **argv, char **envp)
{
	int			status;
	char		*line;
	t_cmdlist	*cmd;
	t_cmdlist	*tmp;
	t_process	*proc;
	t_process	*new_proc;
	char		*username;

	if (argc > 1)
	{
		show_info(argc, argv);
		return (0);
	}
	envl = construct(envp);
	if (!envl)
		perror("Contruct error");
	username = ft_getenv("USER", envl);
	while (1)
	{
		connectsignals();
		line = get_inputstr(username);
		signal(SIGINT, nothing);
	//	printf("parsing...\n");
		cmd = parse_line(line);
	//	printf("parsed: %p\n", cmd);
		free(line);
		if (!cmd)
			continue ;
	//	printf("env detecting...\n");
		parse_env(cmd, envl);
		//t_cmdlist	*tmp_list = cmd;
		/*
		printf("-----------------\n");
	while (tmp_list)
	{
		printf("cmd: %s | type: ", tmp_list->cmd);
		if (tmp_list->type == TSTRING)
			printf("TSTRING");
		else if (tmp_list->type == TCOMMAND)
			printf("TCOMMAND");
		else
			printf("TENV");
		printf(" | piece: %s\n", !tmp_list->piece? "no": "yes");
		tmp_list = tmp_list->next;
	}
	printf("----------------------\n");
*/

//		printf("end...\n");
		tmp = combinate_quote(cmd);
		ft_cmdclear(&cmd, free);
//		printf("converting...\n");
		proc = convert(tmp, envl);
//		printf("converted\n");
		ft_cmdclear(&tmp, free);
		if (!proc)
		{
			printf("Minishell: syntax error near unexpected token `|'\n");
			continue ;
		}
		proc->envp = envl;
		new_proc = proc;
//		printf("starting...\n");
		start_process(new_proc);
		(void)status;
		
		while (new_proc)
		{
			wait(&status);
		//	ft_update_status(status % 255, proc);
		//	ft_update_envp("_", new_proc->path, new_proc->envp);
			new_proc = new_proc->next;
		}
		ft_proclear(&proc, free);
	}
	return (0);
}
