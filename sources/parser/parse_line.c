/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:58:29 by arelmas           #+#    #+#             */
/*   Updated: 2022/07/05 16:18:37 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

#define STR_I 2
#define CHR_I 255
#define GET_STR_I(index) index / CHR_I % STR_I
#define GET_CHR_I(index) index % (CHR_I - 1)

static int	is_endcmd(char c);
static char	*jump_space(char *str);

t_cmdlist	*parse_line(char *line)
{
	char		c;
	char		*cmd;
	char		*env;
	char		buf[STR_I][CHR_I];
	size_t		index;
	t_cmdlist	*list;

	list = 0;
	index = 0;
	line = jump_space(line);
	strings_bzero(buf, 1, STR_I);
	while (line[index])
	{
		c = 0;
		if (line[index] == '"' || line[index] == '\'')
		{
			c = *(line++ + index);
			if (c == '"')
			{
				while (line[index] && line[index] != c)
				{
					if (line[index] != '$')
						buf[GET_STR_I(index)][GET_CHR_I(index)] = line[index];
					else
					{
						if (line[index] && line[index + 1] != c && ft_isalnum(line[index + 1]))
						{
							index++;
							line += index;
							index = 0;
							while (line[index] && line[index] && ft_isalnum(line[index]))
								index++;
							env = ft_getenv(ft_substr(line, 0, ))
						}
						else
							buf[GET_STR_I(index)][GET_CHR_I(index)] = line[index];
					}
				}
			}
			while (line[index] && (line[index] != c))
			{
				buf[GET_STR_I(index)][GET_CHR_I(index)] = line[index];
				index++;
			}
			if (!line[index])
			{
				ft_cmdclear(&list, free);
				return (NULL); 													//free allocated memory
			}
			line++;
			if (!line[index])
			{
				buf[GET_STR_I(index)][GET_CHR_I(index)] = 0;
				ft_cmdadd_back(&list, ft_cmdnew(strings_join(buf, STR_I), TSTRING));
				strings_bzero(buf, 1, STR_I);
				line = jump_space(line + index);
				index = 0;
			}
		}
		else if (!(GET_CHR_I(index + 1)) || (is_endcmd(line[index]) && index))
		{
			buf[GET_STR_I(index)][GET_CHR_I(index)] = 0;
			if (GET_STR_I(index) == STR_I - 1 || (is_endcmd(line[index]) && index))
			{
				ft_cmdadd_back(&list, ft_cmdnew(strings_join(buf, STR_I), TSTRING));
				strings_bzero(buf, 1, STR_I);
				line = jump_space(line + index);
				index = 0;
			}
		}
		else if (is_endcmd(*line) && line[index] != ' ')
		{
			buf[GET_STR_I(index)][GET_CHR_I(index)] = line[index];
			if (line[index] == '>')
			{
				if (line[index + 1] == '>')	
				{
					buf[GET_STR_I(index)][GET_CHR_I(index) + 1] = line[index + 1];
					buf[GET_STR_I(index)][GET_CHR_I(index) + 2] = 0;
					line++;
				}
				else
					buf[GET_STR_I(index)][GET_CHR_I(index) + 1] = 0;
				line++;
				line = jump_space(line + index);
				index = 0;
				ft_cmdadd_back(&list, ft_cmdnew(strings_join(buf, STR_I), TCOMMAND));
				strings_bzero(buf, 1, STR_I);
			}
			else if (line[index] == '<')
			{
				if (line[index + 1] == '<')	
				{
					buf[GET_STR_I(index)][GET_CHR_I(index) + 1] = line[index + 1];
					buf[GET_STR_I(index)][GET_CHR_I(index) + 2] = 0;
					line++;
				}
				else
					buf[GET_STR_I(index)][GET_CHR_I(index) + 1] = 0;
				line++;
				line = jump_space(line + index);
				index = 0;
				ft_cmdadd_back(&list, ft_cmdnew(strings_join(buf, STR_I), TCOMMAND));
				strings_bzero(buf, 1, STR_I);
			}
			else if (line[index] == '|')
			{
				buf[GET_STR_I(index)][GET_CHR_I(index) + 1] = 0;
				ft_cmdadd_back(&list, ft_cmdnew(strings_join(buf, STR_I), TCOMMAND));
				line++;
				line = jump_space(line + index);
				strings_bzero(buf, 1, STR_I);
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
		printf("%s\n", buf[0]);
		printf("you must not bulunmak here\n");
		buf[GET_STR_I(index)][GET_CHR_I(index)] = 0;
		if (check_built_op(buf[GET_STR_I(index)]))
			ft_cmdadd_back(&list, ft_cmdnew(strings_join(buf, STR_I), TCOMMAND));
		ft_cmdadd_back(&list, ft_cmdnew(strings_join(buf, STR_I), TSTRING));
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

static int	is_endcmd(char c)
{
	return (c == ' ' || c == '<' || c == '>' || c == '|');
}

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
