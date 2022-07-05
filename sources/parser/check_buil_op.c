/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_buil_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 03:24:10 by arelmas           #+#    #+#             */
/*   Updated: 2022/07/05 03:30:21 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	check_built_op(char *str)
{
	if (!ft_strcmp(str, ">") || !ft_strcmp(str, ">>") ||
		!ft_strcmp(str, "<") || !ft_strcmp(str, "<<") ||
		!ft_strcmp(str, "|"))
		return (1);
	return (0);
}
