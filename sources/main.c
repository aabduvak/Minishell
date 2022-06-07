/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 07:38:51 by aabduvak          #+#    #+#             */
/*   Updated: 2022/06/07 21:02:30 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <readline/readline.h>

int	main(int argc, char **argv, char **envp)
{
	t_list	*list;
	char	*line;
	char	*full;

	(void)argc;
	(void)argv;
	list = construct(envp);
	while (1)
	{
		line = readline(">>> ");
		full = get_fullpath(ft_getenv("PATH", list), line);
		if (full)
			printf("%s - is builtin: %d\n", full, is_builtin(line));
		else
			perror("minishell");
		free(full);
	}
	return (0);
}
