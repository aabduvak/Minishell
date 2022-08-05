/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsenv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 02:31:39 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/05 10:23:26 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static size_t	copy_env(char *dst, char *input, size_t p_len, t_envp *envl)
{
	char	*env_name;
	char	*env_val;
	size_t	env_len;

	env_name = ft_substr(input, 1, p_len - 1);
	env_val = ft_getenv(env_name, envl);
	env_len = ft_strlen(env_val);
	*dst++ = '\"';
	envcpy(dst, env_val, env_len);
	*dst = '\"';
	return (env_len + 2);
}

char	*parsenv(t_envp *envl, char *input)
{
	size_t	idx;
	size_t	p_len;
	char	*parsed;

	if (!input)
		return (0);
	idx = 0;
	p_len = ft_get_linelen(envl, input);
	parsed = (char *)malloc(sizeof(char) * (p_len + 1));
	while (*input)
	{
		p_len = 0;
		if (input[p_len++] == '$' && ft_check_first_letter(input[p_len++]))
		{
			while (ft_check_letter(*(input + p_len)))
				p_len++;
			idx += copy_env(parsed + idx, input, p_len, envl);
			input += p_len;
		}
		else
			parsed[idx++] = *input++;
	}
	parsed[idx] = 0;
	return (parsed);
}
