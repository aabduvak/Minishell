/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsenv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 02:31:39 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/04 20:13:54 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	check_first_letter(char c)
{
	return (ft_isalpha(c) || c == '_');
}

static int	check_letter(char c)
{
	return (ft_isalpha(c) || ft_isalnum(c) || c == '_');
}

static void	envcpy(char *dst, char *src, size_t size)
{
	if (!src || !dst || !size)
		return ;
	while (*src && size--)
		*dst++ = *src++;
	*dst = 0;
}

static size_t
	parse_len(char *input, int *env_idx, size_t params_len, t_envp *envl)
{
	char	*env_name;
	size_t	size;

	env_name = ft_substr(input, *env_idx + 1, params_len);
	*env_idx += params_len;
	size = ft_strlen(ft_getenv(env_name, envl));
	free(env_name);
	return (size + 2);
}

static size_t	get_len(t_envp *envl, char *input)
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
		{
			env_idx++;
			parsed_len++;
		}
	}
	return (parsed_len);
}

char	*parsenv(t_envp *envl, char *input)
{
	size_t	idx;
	size_t	p_len;
	char	*parsed;
	char	*env_name;

	if (!input)
		return (0);
	idx = 0;
	p_len = get_len(envl, input);
	parsed = (char *)malloc(sizeof(char) * (p_len + 1));
	if (!parsed)
		return (0);
	while (*input)
	{
		p_len = 0;
		if (input[p_len++] == '$' && check_first_letter(input[p_len++]))
		{
			while (check_letter(*(input + p_len)))
				p_len++;
			env_name = ft_substr(input, 1, p_len - 1);
			parsed[idx++] = '\"';
			envcpy(parsed + idx, ft_getenv(env_name, envl),
				ft_strlen(ft_getenv(env_name, envl)));
			idx += ft_strlen(ft_getenv(env_name, envl));
			parsed[idx++] = '\"';
			input += p_len;
		}
		else
			parsed[idx++] = *input++;
	}
	parsed[idx] = 0;
	return (parsed);
}
