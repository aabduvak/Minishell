/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 01:37:14 by aabduvak          #+#    #+#             */
/*   Updated: 2022/08/03 06:06:33 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	echo(t_process *process)
{
	int	i;
	int	compare;

	if (!process->args)
	{
		ft_printf(process->stdfd->_stdout, "\n");
		return ;
	}
	compare = ft_strcmp(process->args[1], "-n");
	i = (compare == 0) + 1;
	while (process->args[i])
	{
		if (process->args[i + 1])
			ft_printf(1, "%s ", process->args[i++]);
		else
			ft_printf(1, "%s", process->args[i++]);
	}
	if (compare)
		ft_printf(1, "\n");
}
