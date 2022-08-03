/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_restart.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 20:19:29 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/03 20:29:01 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_read_restart(t_process *proc, char **dst, char *src)
{
	if (proc->redirect->read)
	{
		free(proc->redirect->read);
		proc->redirect->read = 0;
		if (proc->redirect->delimeter)
			ft_lstclear(&proc->redirect->delimeter, free);
	}
	*dst = ft_strdup(src);
}
