/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 02:32:13 by aabduvak          #+#    #+#             */
/*   Updated: 2022/08/05 02:37:15 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(t_process *process)
{
	int	status;

	if (process && *(process->args + 1))
		status = ft_atoi(process->args[1]) % 256;
	else
		status = 0;
	exit(status);
}
