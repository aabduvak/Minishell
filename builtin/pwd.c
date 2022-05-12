/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 01:37:11 by arelmas           #+#    #+#             */
/*   Updated: 2022/05/12 11:48:58 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	pwd(void)
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

int	main(void)
{
	pwd();
	return (SUCCESS);
}
