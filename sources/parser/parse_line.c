/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:58:29 by arelmas           #+#    #+#             */
/*   Updated: 2022/07/08 19:39:26 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	
*parse(t_cmdlist **list, char buf[STR_I][CHR_I], char *line, int *index);

static void
	end_block(t_cmdlist **list, char buf[STR_I][CHR_I], char *line, int index);

t_cmdlist	*parse_line(char *line)
{
	char		*tmp;
	char		buf[STR_I][CHR_I];
	int			index;
	t_cmdlist	*list;

	list = 0;
	index = 0;
	line = jump_space(line);
	strings_bzero(buf, 1, STR_I);
	while (line[index])
	{
		tmp = parse(&list, buf, line, &index);
		if (!tmp)
			return (ft_cmdclear(&list, free));
		if (tmp == line)
		{
			buf[GET_STR_I(index)][GET_CHR_I(index)] = line[index];
			index++;
		}
		line = tmp;
	}
	if (buf[0][0])
		end_block(&list, buf, line, index);
	return (list);
}

static char	
	*parse(t_cmdlist **list, char buf[STR_I][CHR_I], char *line, int *index)
{
	if (line[*index] == '"' || line[*index] == '\'')
		line = parse_quote(list, buf, line, *index);
	else if (!(GET_CHR_I(*index + 1)) || (is_endcmd(line[*index]) && *index))
		line = buf_over(list, buf, line, *index);
	else if (is_endcmd(*line) && *line != ' ')
		line = parse_bop(list, buf, line, *index);
	else
		return (line);
	*index = 0;
	return (line);
}

static void
	end_block(t_cmdlist **list, char buf[STR_I][CHR_I], char *line, int index)
{
	(void)line;
	buf[GET_STR_I(index)][GET_CHR_I(index)] = 0;
	if (check_built_op(buf[GET_STR_I(index)]))
		ft_cmdadd_back(list, ft_cmdnew(strings_join(buf, STR_I), TCOMMAND));
	else
		ft_cmdadd_back(list, ft_cmdnew(strings_join(buf, STR_I), TSTRING));
}

char	*jump_space(char *str)
{
	if (!str)
		return (NULL);
	while (*str == ' ')
		str++;
	return (str);
}

int	is_endcmd(char c)
{
	return (c == ' ' || c == '<' || c == '>' || c == '|');
}

/*
#include <stdio.h>

int	main()
{
	t_cmdlist *list;
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
		printf("+ |%s| ->", (char *)list->cmd);
		if (list->type == TSTRING)
			printf("string\n");
		else
			printf("b-in operation\n");
		list = list->next;
	}
	return (0);
}
*/
