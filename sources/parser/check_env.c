/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 04:20:32 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/04 23:30:01 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	check_env(char *env_name)
{
	char	*tmp;

	tmp = env_name;
	if (!env_name)
		return (0);
	if (*env_name == '?')
		return (++env_name - tmp);
	if (!ft_isalpha(*env_name) && *env_name != '_')
		return (0);
	while (*++env_name)
		if (!ft_isalnum(*env_name) && *env_name != '_')
			break ;
	return (env_name - tmp);
}
