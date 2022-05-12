/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 02:51:48 by arelmas           #+#    #+#             */
/*   Updated: 2022/05/12 03:14:16 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*ft_getenv(char *name, t_list *envl)
{
	int		idx;
	char	*env_name;

	if (!envl || !name || *name)
		return (NULL);
	while (envl)
	{
		idx = 0;
		env_name = (char *)envl->content;
		if (!env_name)
			continue ;
		while (env_name[idx])
			if (env_name[idx++] == '=')
				break ;
		if (!ft_strncmp(env_name, name, ft_strlen(env_name + idx)))
			return (env_name + idx);
		envl = envl->next;
	}
	return (NULL);
}