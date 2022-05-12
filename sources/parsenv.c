/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsenv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:21:20 by arelmas           #+#    #+#             */
/*   Updated: 2022/05/12 17:06:36 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

size_t	get_len(t_list *envl, char *input)
{
	size_t	params_len;
	size_t	parsed_len;
	char	*env_name;

	parsed_len = 0;
	while(input[parsed_len])
	{
		params_len = 0;
		if (input[parsed_len + params_len++] == '$')
		{
			if (!ft_isalpha(input[parsed_len++ + params_len]))
				continue;
			while (ft_isalpha(input[parsed_len + params_len]) ||
					ft_isalnum(input[parsed_len + params_len]))
				params_len++;
			env_name = ft_substr(input, parsed_len, params_len);
			parsed_len += ft_strlen(ft_getenv(env_name, envl)) - 1;
			free(env_name);
		}
		else
			parsed_len++;
	}
	return (parsed_len);
}

char	*parsenv(t_list *envl, char *input)
{
	return (0);
}
