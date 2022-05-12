/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deconstruct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:43:30 by arelmas           #+#    #+#             */
/*   Updated: 2022/05/12 10:55:36 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	**deconstruct(t_list *envl)
{
	size_t	idx;
	size_t	size;
	char	**envp;

	idx = 0;
	size = ft_lstsize(envl);
	envp = (char **)malloc(sizeof(char *) * (size + 1));
	while (idx < size)
	{
		envp[idx++] = ft_strdup((char *)envl->content);
		envl = envl->next;
	}
	envp[idx] = 0;
	return (envp);
}
