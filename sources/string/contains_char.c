/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contains_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 23:01:59 by aabduvak          #+#    #+#             */
/*   Updated: 2022/08/05 04:40:51 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	contains_char(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (FT_TRUE);
		str++;
	}
	return (FT_FALSE);
}

int	is_relatedbuiltin(char *name)
{
	if (!ft_strcmp(name, BT_CD) || !ft_strcmp(name, BT_EXPORT) || \
	!ft_strcmp(name, BT_EXIT) || !ft_strcmp(name, BT_UNSET))
	{
		return (1);
	}
	return (0);
}
