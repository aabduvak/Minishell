/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 01:37:11 by arelmas           #+#    #+#             */
/*   Updated: 2022/05/12 04:22:24 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	pwd()
{
	char	*buf;

	buf = getcwd(0, 0);
	if (!buf)
	{
		perror("pwd");
		return ;
	}
	printf("%s\n", buf);
	free(buf);
}
