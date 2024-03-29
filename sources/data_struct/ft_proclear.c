/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:27:20 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/09 05:22:01 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_proclear(t_process **proc, void (*del)(void *))
{
	t_process	*tmp;

	if (!proc)
		return ;
	while (*proc)
	{
		tmp = (*proc)->next;
		del((*proc)->name);
		del((*proc)->path);
		free_list((*proc)->args);
		free((*proc)->stdfd);
		ft_redclear((*proc)->redirect);
		free(*proc);
		*proc = tmp;
	}
}
