/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 06:00:26 by aabduvak          #+#    #+#             */
/*   Updated: 2022/07/02 01:17:11 by aabduvak         ###   ########.fr       */
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

char	*get_fullpath(char *path, char *name)
{
	int		i;
	char	**list;
	char	*fullpath;
	char	*tmp;
	int		access_result;

	i = -1;
	list = ft_split(path, ':');
	fullpath = 0;
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
