/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmdnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 03:12:47 by arelmas           #+#    #+#             */
/*   Updated: 2022/07/08 18:42:36 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_cmdlist	*ft_cmdnew(char *cmd, int type)
{
	t_cmdlist	*first;

	first = malloc(sizeof(t_cmdlist));
	if (!first)
		return (NULL);
	first->cmd = cmd;
	first->type = type;
	first->next = NULL;
	return (first);
}
