/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 01:37:11 by arelmas           #+#    #+#             */
/*   Updated: 2022/06/08 06:48:38 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	pwd(t_process *process)
{
	char	*buf;

	buf = getcwd(0, 0);
	if (!buf)
	{
		perror("pwd");
		return ;
	}
	ft_printf(1, "%s\n", buf);
	free(buf);
}
