/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envline_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 02:49:48 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/09 12:06:46 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	ft_envline_len(char *line, t_envp *envl)
{
	int		len;
	int		tmp;
	char	*env_name;
	char	*env_val;

	len = 0;
	while (*line)
	{
		tmp = ft_strchr(line, '$') - line;
		line += tmp;
		if (!*line)
			break ;
		len += tmp;
		tmp = check_env(++line);
		if (tmp)
		{
			env_name = ft_substr(line, 0, tmp);
			env_val = ft_getenv(env_name, envl);
			len += ft_strlen(env_val);
			free(env_name);
		}
		line += tmp;
	}
	return (len);
}
