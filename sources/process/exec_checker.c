/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 06:00:26 by aabduvak          #+#    #+#             */
/*   Updated: 2022/08/09 13:26:07 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	free_list(char **list)
{
	char	**head;

	head = list;
	while (list && *list)
		free(*list++);
	free(head);
}

static int
	init(char ***list, char **path, char *p)
{
	*list = ft_split(p, ':');
	*path = 0;
	return (-1);
}

char	*get_fullpath(char *path, char *name)
{
	int		i;
	char	**list;
	char	*fullpath;
	char	*tmp;
	int		access_result;

	if (!name || !*name)
		return (0);
	i = init(&list, &fullpath, path);
	access_result = access(name, F_OK);
	if (!access_result)
		fullpath = ft_strdup(name);
	while (list[++i] && access_result)
	{
		free(fullpath);
		tmp = ft_strjoin(list[i], "/");
		fullpath = ft_strjoin(tmp, name);
		free(tmp);
		access_result = access(fullpath, F_OK);
	}
	free_list(list);
	if (!access_result && !access(fullpath, X_OK))
		return (fullpath);
	free(fullpath);
	return (NULL);
}
