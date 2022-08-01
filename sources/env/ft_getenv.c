/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 02:51:48 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/01 18:41:24 by arelmas          ###   ########.fr       */
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

char	*ft_getenv(char *name, t_envp *envl)
{
	int		idx;
	char	*env_name;

	if (!envl || !name || !*name)
		return (NULL);
	while (envl)
	{
		idx = 0;
		env_name = (char *)envl->fullstr;
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
