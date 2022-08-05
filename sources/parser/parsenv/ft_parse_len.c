/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 03:05:50 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/05 03:06:08 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

size_t
	ft_parse_len(char *input, int *env_idx, size_t params_len, t_envp *envl)
{
	char	*env_name;
	size_t	size;

	env_name = ft_substr(input, *env_idx + 1, params_len);
	*env_idx += params_len;
	size = ft_strlen(ft_getenv(env_name, envl));
	free(env_name);
	return (size + 2);
}
