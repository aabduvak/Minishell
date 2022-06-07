/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:54:53 by aabduvak          #+#    #+#             */
/*   Updated: 2022/06/07 21:10:12 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	is_builtin(char *command)
{
	if (ft_strcmp(command, BT_EXIT) == 0 || \
		ft_strcmp(command, BT_CD) == 0 || \
		ft_strcmp(command, BT_PWD) == 0 || \
		ft_strcmp(command, BT_WHERE) == 0 || \
		ft_strcmp(command, BT_UNSET) == 0 || \
		ft_strcmp(command, BT_ENV) == 0 || \
		ft_strcmp(command, BT_EXPORT) == 0 || \
		ft_strcmp(command, BT_ECHO) == 0)
		return (FT_TRUE);
	return (FT_FALSE);
}
