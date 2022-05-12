/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD:libft/sources/ft_strchr.c
/*   By: aabduvak <aabduvak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 04:46:41 by aabduvak          #+#    #+#             */
/*   Updated: 2022/05/12 03:05:09 by aabduvak         ###   ########.fr       */
=======
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 01:37:11 by arelmas           #+#    #+#             */
/*   Updated: 2022/05/12 01:41:27 by arelmas          ###   ########.fr       */
>>>>>>> main_arbi:builtin/pwd.c
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	pwd()
{
<<<<<<< HEAD:libft/sources/ft_strchr.c
	if (!str)
		return (NULL);
	while (*str != (char) c && *str != '\0')
		str++;
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
=======
	char	*buf;

	buf = getcwd(0, 0);
	if (!buf)
	{
		perror("pwd");
		return ;
	}
	printf("%s\n", buf);
	free(buf);
>>>>>>> main_arbi:builtin/pwd.c
}
