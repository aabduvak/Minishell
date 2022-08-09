/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 02:52:46 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/09 11:59:31 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*ft_parse_cmd(char *line, t_envp *envl)
{
	size_t	idx;
	size_t	jdx;
	size_t	tmp;
	size_t	line_len;
	char	*parsed;

	line_len = ft_envline_len(line, envl);
	parsed = (char *)malloc(sizeof(char) * (line_len + 1));
	if (!parsed)
		return (NULL);
	idx = 0;
	jdx = 0;
	while (jdx < line_len)
	{
		if (line[idx] == '$' && check_env(line + idx + 1))
			jdx += ft_getenv_val(line, parsed + jdx, &idx, envl);
		else
		{
			tmp = ft_strchr(line + idx, '$') - (line + idx);
			while (tmp--)
				parsed[jdx++] = line[idx++];
		}
	}
	parsed[jdx] = 0;
	return (parsed);
}
