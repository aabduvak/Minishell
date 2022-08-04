/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 01:25:16 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/04 21:04:55 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	cd(t_process *process)
{
	char	*tmp;
	char	*path;
	char	*old_path;
	int		argc;

	if (!process || !process->args)
		return ;
	argc = 0;
	old_path = ft_getenv("PWD", process->envp);
	while (process->args[argc])
		argc++;
	if (argc == 1)
	{
		if (chdir(ft_getenv("HOME", process->envp)))
			perror("cd");
	}
	else if (process->args[1][0] == '~')
	{
		path = ft_strjoin(ft_getenv("HOME", process->envp), "/");
		tmp = ft_strjoin(path, process->args[1] + 2);
		if (chdir(tmp))
			perror("cd");
		free(tmp);
		free(path);
	}
	else if (chdir(process->args[1]) == -1)
		perror("cd");
	ft_update_envp("OLDPWD", old_path, process->envp);
	ft_update_envp("PWD", getcwd(0, 0), process->envp);
}
