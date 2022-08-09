/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 08:08:48 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/09 05:40:59 by arelmas          ###   ########.fr       */
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
