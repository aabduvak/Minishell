/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 02:51:48 by arelmas           #+#    #+#             */
/*   Updated: 2022/05/29 06:01:29 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	env_compare(char *s1, char *s2)
{
	while (*s1 && *s1 != '=' && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 == '=' && !*s2);
}

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
		if (env_name[idx] && env_compare(env_name, name))
			return (env_name + ++idx);
		envl = envl->next;
	}
	return ("");
}
