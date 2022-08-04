/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:22:38 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/04 09:09:29 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	envline_len(char *line, t_envp *envl);
static char	*getenv_val(char *line, char *src, int *idx, t_envp *envl);
static char	*parse_cmd(char *line, t_envp *envl);

void	parse_env(t_cmdlist *list, t_envp *envl)
{
	char	*parsed;

	while (list)
	{
		if (list->type == TENV)
		{
			parsed = parse_cmd(list->cmd, envl);
			free(list->cmd);
			list->cmd = parsed;
			list->type = TSTRING;
		}
		list = list->next;
	}
}

static char	*parse_cmd(char *line, t_envp *envl)
{
	int		idx;
	int		jdx;
	int		tmp;
	int		line_len;
	char	*parsed;

	line_len = envline_len(line, envl);
	parsed = (char *)malloc(sizeof(char) * (line_len + 1));
	if (!parsed)
		return (NULL);
	idx = 0;
	jdx = 0;
	while (jdx < line_len)
	{
		if (line[idx] == '$')
			jdx += ft_getenv_val(line, parsed + jdx, &idx envl);
		else
		{
			tmp = ft_strchr(line + idx, '$') - (line + idx);
			while (tmp--)
				parsed[jdx++] = line[idx++];
		}
	}
	parsed[jdx] = 0;
	return (parsed);
}

static int	envline_len(char *line, t_envp *envl)
{
	int		len;
	int		tmp;
	char	*env_name;
	char	*env_val;

	len = 0;
	while (*line)
	{
		tmp = ft_strchr(line, '$') - line;
		line += tmp;
		len += tmp;
		if (!*line)
			break ;
		tmp = check_env(++line);
		len += !tmp;
		if (tmp)
		{
			env_name = ft_substr(line, 0, tmp);
			env_val = ft_getenv(env_name, envl);
			len += ft_strlen(env_val);
			free(env_name);
		}
		line += tmp;
	}
	return (len);
}

static int	ft_getenv_val(char *line, char *src, int *idx, t_envp *envl)
{
	int		env_len;
	char	*env_name;
	char	*env_val;

	env_len = check_env(line + *idx + 1);
	if (env_len)
		return ;
	env_name = ft_substr(line + *idx, 1, env_len);
	env_val = ft_getchar(env_name, envl);
	ft_strcpy(src, env_val);
	*idx += ft_strlen(env_name) + 1;
	return (ft_strlen(env_val));
}
