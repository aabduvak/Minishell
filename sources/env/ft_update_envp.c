/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_envp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:37:11 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/04 20:46:09 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*envl_join(char *key, char *value);

void	ft_update_envp(char *key, char *value, t_envp *envl)
{
	if (!key || !envl)
		return ;
	while (envl)
	{
		if (!ft_strcmp(key, envl->key))
		{
			free(envl->value);
			free(envl->fullstr);
			envl->value = ft_strdup(value);
			envl->fullstr = envl_join(key, value);
			return ;
		}
		envl = envl->next;
	}
}

static char	*envl_join(char *key, char *value)
{
	char	*tmp;
	char	*res;

	if (!key)
		return (0);
	tmp = ft_strjoin(key, "=");
	if (!tmp)
		return (0);
	if (!value)
		return (tmp);
	res = ft_strjoin(tmp, value);
	free(tmp);
	if (!res)
		return (0);
	return (res);
}
