/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 22:12:52 by aabduvak          #+#    #+#             */
/*   Updated: 2022/08/09 03:29:29 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*change_color(char *str, char *color)
{
	char	*tmp;
	char	*res;

	tmp = ft_strjoin(color, str);
	res = ft_strjoin(tmp, RESET);
	free(tmp);
	return (res);
}

char	*get_input(char *username)
{
	char	*input;
	char	*prompt;

	prompt = create_prompt(username);
	input = readline(prompt);
	if (!input)
		return (input);
	add_history(input);
	free(prompt);
	return (input);
}

char	*create_prompt(char *username)
{
	char		*prompt;
	char		*cwd;
	char		*tmp;
	char		*tmp2;
	int			len;

	username = change_color(username, BOLD_GREEN);
	len = ft_strlen(username);
	cwd = getcwd(NULL, 0);
	tmp = ft_strrchr(cwd, '/');
	tmp = ft_substr(tmp, 1, ft_strlen(tmp));
	tmp2 = tmp;
	tmp = change_color(tmp, BOLD_BLUE);
	free(tmp2);
	prompt = ft_calloc(sizeof(char), ft_strlen(username) + ft_strlen(tmp) + 5);
	ft_memcpy(prompt, username, len);
	prompt[len] = ':';
	ft_memcpy(prompt + ft_strlen(prompt), tmp, ft_strlen(tmp));
	ft_memcpy(prompt + ft_strlen(prompt), "$ ", 5);
	free(cwd);
	free(tmp);
	free(username);
	return (prompt);
}
