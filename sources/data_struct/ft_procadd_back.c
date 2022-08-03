/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_procadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:24:09 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/03 02:41:02 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	*ft_procadd_back(t_process **proc, t_process *new)
{
	t_process	*tmp;

	printf("---start\n");
	if (!proc)
		return (NULL);
	printf("he\n");
	if (!*proc)
	{
		*proc = new;
		printf("iste\n");
		(*proc)->next = 0;
		printf("degil\n");
		(*proc)->prev = 0;
		return (new);
	}
	tmp = *proc;
	printf("while\n");
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	printf("pff\n");
	tmp->next = new;
	new->prev = tmp;
	printf("----the end.\n");
	return (new);
}
