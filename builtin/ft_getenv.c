/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 02:51:48 by arelmas           #+#    #+#             */
/*   Updated: 2022/05/12 11:23:26 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*ft_getenv(char *name, t_list *envl)
{
	int		idx;
	char	*env_name;

	if (!envl || !name || !*name)
		return (NULL);
	while (envl)
	{
		idx = 0;
		env_name = (char *)envl->content;
		if (!env_name)
			continue ;
		while (env_name[idx] && env_name[idx] != '=')
			idx++;
		if (env_name[idx] &&
				!ft_strncmp(env_name, name, idx++))
			return (env_name + idx);
		envl = envl->next;
	}
	return ("");
}
