/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:58:29 by arelmas           #+#    #+#             */
/*   Updated: 2022/07/03 17:18:25 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

#define STRi 2
#define CHRi 255
#define GET_STRI(index) index / CHRi % STRi
#define GET_CHRI(index) index % (CHRi - 1)

static char	*jump_space(char *str);

t_list	*parse_line(char *line)
{
	char	*cmd;
	char	buf[STR][255];
	size_t	index;
	t_list	*list;

	list = 0;
	index = 0;
	line = jump_space(line);
	while (line[index])
	{
		if (line[index] == '"' || line[index] == '\'')
		{
			line++;
			while (line[index] && (line[index] != '\'' && line[index] != '"'))
				index++;
		}
		else if (line[index] == ' ')
		{
			ft_lstadd_back(&list, ft_lstnew(ft_substr(line, 0, index)));
			line = jump_space(line + index);
			index = -1;
		}
		else
			buf[GET_STRI(index)][GET_CHRI(index)] = line[index];
		if (!GET_CHRI(index + 1))
		{
			buf[GET_STRI(index)][GET_CHRI(index) + 1] = 0;
			if (GET_STRI(index) == STRi - 1)
				ft_lstadd_back(&list, ft_lstnew(ft_strjoin(buf[0], buf[1])));
		}

		index++;
	}
	if (index)
		ft_lstadd_back(&list, ft_lstnew(ft_substr(line, 0, index)));
	return (list);
}

static char	*jump_space(char *str)
{
	if (!str)
		return (NULL);
	while (*str == ' ')
		str++;
	return (str);
}

#include <stdio.h>

int	main()
{
	t_list *list;

	list = parse_line("'ls' > 'a' | 'cat' '-e'");
	while (list)
	{
		printf("+ |%s|\n", (char *)list->content);
		list = list->next;
	}
	return (0);
}
