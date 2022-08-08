/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 02:59:28 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/08 19:22:37 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	find_env(char *line, int quote)
{
	(void)quote;
	while (line && *line && *line != '$')
	{
		if (*line == '"')
			break ;
		line++;
	}
	if (!*line || !check_env(line + 1) || (*line == '"'))
		return (0);
	return (1);
}
