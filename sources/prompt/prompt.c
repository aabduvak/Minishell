/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 22:12:52 by aabduvak          #+#    #+#             */
/*   Updated: 2022/08/01 23:09:54 by aabduvak         ###   ########.fr       */
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

char	*get_input(void)
{
	char	*input;
	char	*prompt;

	prompt = create_prompt();
	if (!prompt)
		prompt = "$: ";
	input = readline(prompt);
	if (!input)
		return (input);
	add_history(input);
	free(prompt);
	return (input);
}

char	*create_prompt(void)
{
	static char	*username;
	char		*prompt;
	char		*cwd;
	char		*tmp;
	int			len;

	username = getenv("USER");
	if (!username)
		username = "NOUSERNAME";
	username = change_color(username, BOLD_GREEN);
	len = ft_strlen(username);
	cwd = getcwd(NULL, 0);
	tmp = ft_strrchr(cwd, '/');
	tmp = ft_substr(tmp, 1, ft_strlen(tmp));
	tmp = change_color(tmp, BOLD_BLUE);
	prompt = ft_calloc(sizeof(char), ft_strlen(username) + ft_strlen(tmp) + 5);
	ft_memcpy(prompt, username, len);
	prompt[len] = ':';
	ft_memcpy(prompt + ft_strlen(prompt), tmp, ft_strlen(tmp));
	ft_memcpy(prompt + ft_strlen(prompt), "$ ", 5);
	free(cwd);
	free(tmp);
	return (prompt);
}
