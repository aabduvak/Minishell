/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42ISTANBUL.COM.TR>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 07:38:51 by aabduvak          #+#    #+#             */
/*   Updated: 2022/06/01 16:17:27 by aabduvak         ###   ########.fr       */
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
	line = malloc(10000);
	while (1)
	{
		line = readline(">>> ");
		full = get_fullpath(ft_getenv("PATH", list), line);
		if (full)
			printf("%s\n", full);
		else
			perror("minishell");
		free(full);
		free(line);
	}
	return (0);
}
