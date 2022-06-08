/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 07:38:51 by aabduvak          #+#    #+#             */
/*   Updated: 2022/06/08 06:05:13 by aabduvak         ###   ########.fr       */
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
	while (1)
	{
		line = ft_split(readline(">>> "), ' ');
		full = get_fullpath(ft_getenv("PATH", process->envp), line[0]);
		if (is_builtin(line[0]))
		{
			if (line[1])
				process->args = line + 1;
			else
				process->args = 0;
			export(process);
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
