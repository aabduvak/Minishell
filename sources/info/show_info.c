/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:15:24 by aabduvak          #+#    #+#             */
/*   Updated: 2022/08/05 02:47:49 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "info.h"

static void	print_version(char *line)
{
	char	**lines;

	lines = ft_split(line, ' ');
	if (!ft_strcmp(lines[0], "VERSION"))
	{
		printf("42istanbul minishell, version %s\n", lines[1]);
		printf("Copyright (C) 2022 42Istanbul, Inc.\n");
		printf("License GPLv3+: GPL version 3\n");
		printf("This is free software; you are free to change it.\n");
		printf("There is NO WARRANTY, to the extent permitted by law.\n");
	}
	free_list(lines);
}

static void	print_author(char *line)
{
	char	**lines;

	lines = ft_split(line, ' ');
	if (!ft_strcmp(lines[0], "AUTHOR"))
	{
		printf("Developed by:\t%s %s\n", lines[1], lines[2]);
		printf("Github:\t\t%s\n", lines[3]);
	}
	free_list(lines);
}

static void	print_help(void)
{
	printf("minishell, version 1.0.0\n");
	printf("Usage:\tbash [option] ...\n");
	printf("\tbash [option] script-file (comming soon!)...\n");
	printf("minishell options:\n");
	printf("\t--help\n");
	printf("\t--version\n");
	printf("\t--author\n");
	printf("\t--update\n");
}

void	show_info(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	while (argc > ++i)
	{
		fd = open("INFO", O_RDONLY);
		if (fd == -1)
			return ;
		while (1)
		{
			line = get_next_line(fd);
			if (!line)
				break ;
			if (argc > 1 && !ft_strcmp(argv[i], VERSION))
				print_version(line);
			else if (argc > 1 && !ft_strcmp(argv[i], AUTHOR))
				print_author(line);
			free(line);
		}
		close(fd);
		if (!ft_strcmp(argv[i], HELP))
			print_help();
	}
}
