/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:39:15 by arelmas           #+#    #+#             */
/*   Updated: 2022/05/12 10:54:11 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_list	*construct(char	**envp)
{
	int		idx;
	t_list	*envl;

	if (!envp)
		return (0);
	idx = 0;
	envl = 0;
	while (envp[idx])
		ft_lstadd_back(&envl, ft_lstnew(ft_strdup(envp[idx++])));
	return (envl);
}
