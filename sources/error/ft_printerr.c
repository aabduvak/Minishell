/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printerr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 03:37:30 by aabduvak          #+#    #+#             */
/*   Updated: 2022/07/31 05:13:58 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	ft_printerr(char *name, int status)
{
	if (status == ER_NOTPERMITTED)
		printf("%s: %s\n", name, E_NOTPERMITTED);
	else if (status == ER_EXEC)
		printf("%s: %s\n", name, E_EXEC);
	else if (status == ER_NOCOMM)
		printf("%s: %s\n", name, E_NOCOMM);
	else if (status == ER_NOPROC)
		printf("%s: %s\n", name, E_NOPROC);
	else if (status == ER_NOFILE)
		printf("%s: %s\n", name, E_NOFILE);
	else if (status == ER_RUNPROC)
		printf("%s: %s\n", name, E_RUNPROC);
	else if (status == ER_ISDIR)
		printf("%s: %s\n", name, E_ISDIR);
	else if (status == ER_NOTDIR)
		printf("%s: %s\n", name, E_NOTDIR);
	else if (status == ER_NOTDIR)
		printf("%s: %s\n", name, E_NOTDIR);
	else if (status == ER_PIPES)
		printf("%s: %s\n", name, E_PIPES);
	else if (status == ER_TIMEDOUT)
		printf("%s: %s\n", name, E_TIMEDOUT);
	else if (status == ER_CONNREFUSED)
		printf("%s: %s\n", name, E_CONNREFUSED);
}

void	ft_error(t_process *process, int status)
{
	
}
