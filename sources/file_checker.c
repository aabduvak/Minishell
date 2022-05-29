/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 06:00:26 by aabduvak          #+#    #+#             */
/*   Updated: 2022/05/29 06:00:54 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell>

int	file_checker(char *path, char *name)
{
	int		i;
	char	**list;
	int		result;
	char	*fullpath;
	char	*tmp;

	i = -1;
	result = -1;
	list = ft_split(path, ':');
	while (list[++i])
	{
		tmp = ft_strjoin(list[i], "/");
		fullpath = ft_strjoin(tmp, name);
		result = access(fullpath, F_OK | X_OK);
		free(tmp);
		free(fullpath);
		free(list[i]);
		if (!result)
			break ;
	}
	free(list);
	return (result);
}

char	*get_fullpath(char *path, char *name)
{
	int		i;
	char	**list;
	char	*fullpath;
	char	*tmp;

	i = -1;
	list = ft_split(path, ':');
	fullpath = 0;
	while (list[++i])
	{
		tmp = ft_strjoin(list[i], "/");
		fullpath = ft_strjoin(tmp, name);
		free(tmp);
		free(list[i]);
		if (!file_checker(fullpath, name))
			break ;
	}
	free(list);
	return (fullpath);
}

