/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 04:20:32 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/01 04:34:37 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	check_env(char *env_name)
{
	char	*tmp;

	tmp = env_name;
	if (!env_name)
		return (0);
	if (!ft_isalpha(*env_name) && *env_name != '_')
		return (0);
	while (*++env_name)
		if (!ft_isalnum(*env_name) && *env_name != '_')
			return (0);
	return (env_name - tmp);
}
