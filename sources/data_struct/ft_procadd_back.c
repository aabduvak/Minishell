/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_procadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:24:09 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/03 04:50:51 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	*ft_procadd_back(t_process **proc, t_process *new)
{
	t_process	*tmp;

	if (!proc)
		return (NULL);
	if (!*proc)
	{
		*proc = new;
		(*proc)->next = 0;
		(*proc)->prev = 0;
		return (new);
	}
	tmp = *proc;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
	new->prev = tmp;
	return (new);
}
