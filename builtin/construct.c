/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:39:15 by arelmas           #+#    #+#             */
/*   Updated: 2022/05/12 12:09:02 by aabduvak         ###   ########.fr       */
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
