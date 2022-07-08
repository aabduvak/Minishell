/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_procinit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:41:43 by arelmas           #+#    #+#             */
/*   Updated: 2022/07/08 18:43:16 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_procinit(t_process *proc)
{
	if (!proc)
		return ;
	proc->name = 0;
	proc->path = 0;
	proc->args = 0;
	proc->next = 0;
	proc->prev = 0;
	proc->redirect = (t_redirect *)malloc(sizeof(t_redirect));
	proc->redirect->write = 0;
	proc->redirect->read = 0;
	proc->redirect->delimeter = 0;
	proc->redirect->overwrite = 0;
	proc->stdfd = (t_stdfd *)malloc(sizeof(t_redirect));
}
