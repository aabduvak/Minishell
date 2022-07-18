/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 07:38:51 by aabduvak          #+#    #+#             */
/*   Updated: 2022/07/18 22:10:57 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	main(int argc, char **argv, char **envp)
{
	char		**line;
	char		*full;
	t_process	*process;
	char		*lines;

	(void)argc;
	(void)argv;
	full = 0;
	process = malloc(sizeof(t_process));
	process->envp = construct(envp);
	process->stdfd = malloc(sizeof(t_stdfd));
	process->stdfd->_stdout = 0;
	connectsignals();
	while (1)
	{
		lines = get_input();
		line = ft_split(lines, ' ');
		process->name = line[0];
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
		free_list(line);
	}
	return (0);
}
