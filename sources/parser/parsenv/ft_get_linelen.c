/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_linelen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 03:06:58 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/05 03:08:54 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

size_t	ft_get_linelen(t_envp *envl, char *input)
{
	size_t	params_len;
	size_t	parsed_len;
	size_t	env_idx;
	char	c;

	env_idx = 0;
	parsed_len = 0;
	while (input[env_idx])
	{
		params_len = 0;
		c = input[env_idx + params_len++];
		if (c == '$')
		{
			if (params_len++ && !(ft_isalpha(c) || c == '_') && ++env_idx)
				continue ;
			while (check_letter(input[env_idx + params_len]))
				params_len++;
			parsed_len += parse_len(input, (int *)&env_idx, params_len, envl);
		}
		else
			env_idx += !!++parse_len;
	}
	return (parsed_len);
}
