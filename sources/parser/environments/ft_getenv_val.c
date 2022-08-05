/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv_val.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 02:51:08 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/05 02:52:32 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	ft_getenv_val(char *line, char *src, size_t *idx, t_envp *envl)
{
	int		env_len;
	char	*env_name;
	char	*env_val;

	env_len = check_env(line + *idx + 1);
	if (!env_len)
		return (0);
	env_name = ft_substr(line + *idx, 1, env_len);
	env_val = ft_getenv(env_name, envl);
	ft_strcpy(src, env_val);
	*idx += ft_strlen(env_name) + 1;
	return (ft_strlen(env_val));
}
