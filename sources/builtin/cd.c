/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 01:25:16 by arelmas           #+#    #+#             */
/*   Updated: 2022/07/02 01:33:45 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	cd(t_process *process)
{
	char	*tmp;
	char	*path;
	int	argc;
	
	if (!process || !process->args)
		return ;
	argc = 0;
	while (process->args[argc])
		argc++;
	if (argc == 1)
	{
		printf("home: %s\n", ft_getenv("home", process->envp));
		if (chdir(ft_getenv("HOME", process->envp)))
			perror("cd");
		return ;
	}
	else if (process->args[1][0] == '~')
	{
		path = ft_strjoin(ft_getenv("HOME", process->envp), "/");
		tmp = ft_strjoin(path, process->args[1] + 2);
		printf("%s\n", tmp);
		if (chdir(tmp))
			perror("cd");
		free(tmp);
		free(path);
	}
	else if (chdir(process->args[1]) == -1)
		perror("cd");
}
