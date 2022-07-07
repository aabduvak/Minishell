/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmdclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 03:18:03 by arelmas           #+#    #+#             */
/*   Updated: 2022/07/07 17:34:21 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <data_struct.h>

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
