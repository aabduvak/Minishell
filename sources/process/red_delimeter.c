/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_delimeter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 05:30:56 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/09 05:42:07 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	nonext(char *buf, int pipes[2], int readed)
{
	char	*buf2;

	buf2 = ft_strjoin(buf, "\n");
	write(pipes[1], buf2, readed + 1);
	free(buf2);
}

static void	reconnect(int std_in)
{
	dup2(std_in, 0);
	close(std_in);
	connectsignals();
}

static int	next(char *buf, t_list *del, int readed)
{
	return (!ft_strncmp(buf, (char *)del->content,
			readed - (readed > 1)) && readed);
}

int	red_delimeter(t_list *del, int read_red)
{
	int		std_in;
	int		pipes[2];
	char	*buf;

	if (!read_red && pipe(pipes))
		return (ERROR);
	std_in = dup(0);
	signal(SIGINT, del_handler);
	while (1)
	{
		buf = readline("> ");
		if (next(buf, del, ft_strlen(buf)))
		{
			if (!del->next)
				break ;
			del = del->next;
		}
		else if (ft_strlen(buf) > 0 && !del->next && !read_red)
			nonext(buf, pipes, ft_strlen(buf));
	}
	reconnect(std_in);
	if (close(pipes[1]) || dup2(pipes[0], 0) == -1)
		return (ERROR);
	return (0);
}
