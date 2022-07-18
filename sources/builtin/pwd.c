/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 01:37:11 by arelmas           #+#    #+#             */
/*   Updated: 2022/07/18 21:41:36 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	pwd(t_process *process)
{
	char	*buf;

	buf = getcwd(0, 0);
	if (!buf || !process)
	{
		perror("pwd");
		return ;
	}
	ft_printf(1, "%s\n", buf);
	free(buf);
}
