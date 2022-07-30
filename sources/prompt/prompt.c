/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 22:12:52 by aabduvak          #+#    #+#             */
/*   Updated: 2022/07/31 01:05:19 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_input(void)
{
	char	*input;
	char	*prompt;

	prompt = create_prompt();
	if (!prompt)
		prompt = ":> ";
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
	len = ft_strlen(username);
	cwd = getcwd(NULL, 0);
	tmp = ft_strrchr(cwd, '/');
	tmp = ft_substr(tmp, 1, ft_strlen(tmp));
	prompt = ft_calloc(sizeof(char), ft_strlen(username) + ft_strlen(tmp) + 5);
	ft_memcpy(prompt, username, len);
	prompt[len] = '@';
	ft_memcpy(prompt + ft_strlen(prompt), tmp, ft_strlen(tmp));
	ft_memcpy(prompt + ft_strlen(prompt), ":> ", 5);
	free(cwd);
	free(tmp);
	return (prompt);
}
