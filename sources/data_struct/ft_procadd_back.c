/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_procadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:24:09 by arelmas           #+#    #+#             */
/*   Updated: 2022/07/08 15:47:54 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <data_struct.h>

void	*ft_cmdadd_back(t_process **proc, t_process *new)
{
	t_process	*tmp;

	if (!proc)
		return (NULL);
	if (!*proc)
	{
		*proc = new;
		return (new);
	}
	tmp = *proc;
	while (tmp->next)
		proc = proc->next;
	proc->next = new;
	return (new);
}
