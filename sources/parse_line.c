/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:11:10 by arelmas           #+#    #+#             */
/*   Updated: 2022/06/28 15:25:54 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_list	*parse_line(char *line)
{
	size_t	index;
	t_list	*list;

	list = 0;
	index = 0;
	while (*line == ' ')
		line++;
	while (line[index])
	{
		if (line[index] == ' ')
		{
			ft_lstadd_back(&tmp, ft_lstnew(ft_substr(line, 0, index)));
			line = line + index;
			index = 1;
			continue;
		}
		if (line[index] == '"' || line[index] == ''')
		{
			
		}
	}
}
