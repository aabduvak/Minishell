/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_access.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:11:34 by arelmas           #+#    #+#             */
/*   Updated: 2022/07/31 23:24:51 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	proc_access(char *name)
{
	return (ft_strcmp(name, "cd") && ft_strcmp(name, "env") &&
		ft_strcmp(name, "unset") && ft_strcmp(name, "echo") &&
		ft_strcmp(name, "pwd") && ft_strcmp(name, "export") &&
		ft_strcmp(name, "exit"));
}
