/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 08:08:48 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/08 23:44:59 by arelmas          ###   ########.fr       */
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

int	red_delimeter(t_list *del, int read_red)
{
	int		readed;
	int		std_in;
	int		pipes[2];
	char	*buf;
	char	*buf2;

	if (!read_red && pipe(pipes))
		return (ERROR);
	std_in = dup(0);
	signal(SIGINT, del_handler);
	while (1)
	{
		buf = readline("> ");
		readed = ft_strlen(buf);
		if (!ft_strncmp(buf, (char *)del->content, readed - (readed > 1)) && readed)
		{
			if (!del->next)
				break ;
			del = del->next;
			continue ;
		}
		if (readed > 0 && !del->next && !read_red)
		{
			buf2 = ft_strjoin(buf, "\n");
			write(pipes[1], buf2, readed + 1);
			free(buf2);
		}
	}
	dup2(std_in, 0);
	close(std_in);
	connectsignals();
	if (close(pipes[1]) || dup2(pipes[0], 0) == -1)
		return (ERROR);
	return (0);
}
