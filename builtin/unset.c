/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 03:16:44 by aabduvak          #+#    #+#             */
/*   Updated: 2022/05/12 03:47:52 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	unset(t_list *lst, char *name)
{
	char	**str;
	t_list	*tmp;

	while (lst)
	{
		tmp = lst->next;
		str = ft_split((char *) lst->content, '=');
		if (!ft_strncmp(str[0], name, ft_strlen(name)))
		{
			ft_lstdelone(lst, free);
			lst = tmp;
			return (SUCCESS);
		}
		lst = lst->next;
		free(str[0]);
		free(str[1]);
		free(str[2]);
		free(str);
	}
	return (FAILED);
}
