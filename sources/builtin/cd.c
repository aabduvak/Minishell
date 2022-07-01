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

	if (!process->args)
	{
		if (chdir(ft_getenv("HOME", process->envp)))
			perror("cd");
	}
	else if (process->args[0][0] == '~')
	{
		path = ft_strjoin(ft_getenv("HOME", process->envp), "/");
		tmp = ft_strjoin(path, process->args[0] + 2);
		printf("%s\n", tmp);
		if (chdir(tmp))
			perror("cd");
		free(tmp);
		free(path);
	}
	else if (chdir(process->args[0]) == -1)
		perror("cd");
}
