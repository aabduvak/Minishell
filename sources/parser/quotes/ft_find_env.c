/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 02:59:28 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/09 04:49:58 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	find_env(char *line, int quote)
{
	while (line && *line && *line != '$')
	{
		if (quote && *line == '"')
			break ;
		line++;
	}
	if (!*line || !check_env(line + 1) || (quote && *line == '"') )
		return (0);
	return (1);
}
