/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 08:08:48 by arelmas           #+#    #+#             */
/*   Updated: 2022/07/02 01:16:09 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	red_read(const char *file_name)
{
	int	fd;

	fd = open (file_name, O_RDONLY);
	if (fd < 0 || dup2(fd, 0) == -1)
		return (ERROR);
	return (0);
}

int	red_write(const char *file_name)
{
	int	fd;

	fd = open(file_name, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd < 0 || dup2(fd, 1) == -1)
		return (ERROR);
	return (0);
}

int	red_overwrite(const char *file_name)
{
	int	fd;

	fd = open(file_name, O_CREAT | O_APPEND | O_WRONLY, 0644);
	if (fd < 0 || dup2(fd, 1) == -1)
		return (ERROR);
	return (0);
}

int	red_delimeter(const char *del)
{
	int		readed;
	int		pipes[2];
	char	buf[255];

	if (pipe(pipes))
		return (ERROR);
	while (1)
	{
		ft_printf(1, "> ");
		readed = read(0, buf, 255);
		if (!ft_strncmp(buf, del, readed - (readed > 1)))
			break ;
		if (readed > 0)
			write(pipes[1], buf, readed);
	}
	if (close(pipes[1]) || dup2(pipes[0], 0) == -1)
		return (ERROR);
	return (0);
}
