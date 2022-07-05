/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmdclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 03:18:03 by arelmas           #+#    #+#             */
/*   Updated: 2022/07/05 03:19:30 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <data_struct.h>

void	ft_cmdclear(t_cmdlist **cmdlist, void (*del)(void *))
{
	t_cmdlist	*tmp;

	if (!cmdlist)
		return ;
	while (*cmdlist)
	{
		tmp = (*cmdlist)->next;
		del((*cmdlist)->cmd);
		free(*cmdlist);
		*cmdlist = tmp;
	}
}
