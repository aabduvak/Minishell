/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_access.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:11:34 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/05 04:18:58 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	proc_access(char *name)
{
	return (ft_strcmp(name, BT_CD) && ft_strcmp(name, BT_ENV) && \
		ft_strcmp(name, BT_UNSET) && ft_strcmp(name, BT_ECHO) && \
		ft_strcmp(name, BT_PWD) && ft_strcmp(name, BT_EXPORT) && \
		ft_strcmp(name, BT_EXIT));
}
