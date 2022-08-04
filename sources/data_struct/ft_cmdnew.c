/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmdnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 03:12:47 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/03 21:50:10 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_cmdlist	*ft_cmdnew(char *cmd, int type, int piece)
{
	t_cmdlist	*first;

	first = malloc(sizeof(t_cmdlist));
	if (!first)
		return (NULL);
	first->cmd = cmd;
	first->type = type;
	first->piece = piece;
	first->next = NULL;
	return (first);
}
