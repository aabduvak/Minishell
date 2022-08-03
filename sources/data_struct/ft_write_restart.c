/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redrestart.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:09:54 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/03 20:18:28 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_write_restart(t_process *proc, char **dst, char *src)
{
	if (proc->redirect->write)
	{
		free(proc->redirect->write);
		proc->redirect->write = 0;
	}
	if (proc->redirect->overwrite)
	{
		free(proc->redirect->overwrite);
		proc->redirect->overwrite = 0;
	}
	*dst = ft_strdup(src);
}
