/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:58:29 by arelmas           #+#    #+#             */
/*   Updated: 2022/07/05 02:04:50 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

#define STR_I 2
#define CHR_I 255
#define GET_STR_I(index) index / CHR_I % STR_I
#define GET_CHR_I(index) index % (CHR_I - 1)

static char	*jump_space(char *str);

t_list	*parse_line(char *line)
{
	char	c;
	char	*cmd;
	char	buf[STR_I][CHR_I];
	size_t	index;
	t_list	*list;

	list = 0;
	index = 0;
	line = jump_space(line);
	strings_bzero(buf, 1, STR_I);
	while (line[index])
	{
		if (line[index] == '"' || line[index] == '\'')
		{
			c = *(line++ + index);
			while (line[index] && (line[index] != c))
			{
				buf[GET_STR_I(index)][GET_CHR_I(index)] = line[index];
				index++;
			}
			if (!line[index])
				return (NULL); 													//free allocated memory
			line++;
		}
		else if (!(GET_CHR_I(index + 1)) || line[index] == ' ')
		{
			buf[GET_STR_I(index)][GET_CHR_I(index)] = 0;
			if (GET_STR_I(index) == STR_I - 1 || line[index] == ' ')
			{
				ft_lstadd_back(&list, ft_lstnew(strings_join(buf, STR_I)));
				strings_bzero(buf, 1, STR_I);
				line = jump_space(line + index);
				index = 0;
			}
		}
		else
		{
			buf[GET_STR_I(index)][GET_CHR_I(index)] = line[index];
			index++;
		}
	}
	if (buf[0][0])
	{
		buf[GET_STR_I(index)][GET_CHR_I(index)] = 0;
		ft_lstadd_back(&list, ft_lstnew(strings_join(buf, STR_I)));
	}
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
	char	buf[500] = {0};
	int		readed;
	
	readed = read(0, buf, 500);
	buf[readed - 1] = 0;
	list = parse_line(buf);
	if (!list)
		printf("error\n");
	while (list)
	{
		//printf("while...\n");
		printf("+ |%s|\n", (char *)list->content);
		list = list->next;
	}
	return (0);
}
