/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmdclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 03:18:03 by arelmas           #+#    #+#             */
/*   Updated: 2022/07/08 18:42:19 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	*ft_cmdclear(t_cmdlist **cmdlist, void (*del)(void *))
{
	t_cmdlist	*tmp;

	if (!cmdlist)
		return (NULL);
	while (*cmdlist)
	{
		tmp = (*cmdlist)->next;
		del((*cmdlist)->cmd);
		free(*cmdlist);
		*cmdlist = tmp;
	}
	return (NULL);
}
