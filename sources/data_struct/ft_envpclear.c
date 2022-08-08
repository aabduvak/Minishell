/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envpclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:35:33 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/09 02:46:21 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_envpclear(t_envp *envl)
{
	t_envp	*tmp;

	while (envl)
	{
		tmp = envl->next;
		free(envl->key);
		free(envl->value);
		free(envl->fullstr);
		free(envl);
		envl = tmp;
	}
}
