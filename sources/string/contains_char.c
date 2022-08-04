/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contains_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 23:01:59 by aabduvak          #+#    #+#             */
/*   Updated: 2022/08/04 23:02:09 by aabduvak         ###   ########.fr       */
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
