/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 02:53:08 by aabduvak          #+#    #+#             */
/*   Updated: 2022/05/12 14:25:26 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	env(t_list *lst)
{
	if (!lst)
		return ;
	while (lst)
	{
		printf("%s\n", (char *) lst->content);
		lst = lst->next;
	}
}
