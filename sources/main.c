/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 07:38:51 by aabduvak          #+#    #+#             */
/*   Updated: 2022/06/08 14:54:30 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <readline/readline.h>

int	main(int argc, char **argv, char **envp)
{
	char		**line;
	char		*full;
	t_process	*process;

	(void)argc;
	(void)argv;
	process = malloc(sizeof(t_process));
	process->envp = construct(envp);
	process->stdfd = malloc(sizeof(t_stdfd));
	process->stdfd->_stdout = 0;
	while (1)
	{
		line = ft_split(readline(">>> "), ' ');
		process->name = line[0];
		full = get_fullpath(ft_getenv("PATH", process->envp), line[0]);
		if (is_builtin(process->name))
		{
			if (line[1])
				process->args = line + 1;
			else
				process->args = 0;
			run_builtin(process);
		}
		else if (full)
			ft_printf(0, "%s\n", full);
		else
			perror("minishell");
		free(full);
		free(line);
	}
	return (0);
}
