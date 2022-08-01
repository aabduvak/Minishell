/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmdadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 03:14:57 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/01 20:50:29 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_cmdadd_back(t_cmdlist **cmdlist, t_cmdlist *new)
{
	t_cmdlist	*item;

	if (!cmdlist)
		return ;
	if (!*cmdlist)
	{
		*cmdlist = new;
		return ;
	}
	item = *cmdlist;
	while (item->next != NULL)
		item = item->next;
	item->next = new;
}
