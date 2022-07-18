/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:00:51 by aabduvak          #+#    #+#             */
/*   Updated: 2022/07/18 21:05:43 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Mkaramuk'tan çalındı :D 

char	*get_input(void)
{
	char	*input;
	char	*prompt;

	prompt = create_prompt();
	input = readline(prompt);
	add_history(input);
	free(prompt);
	return (input);
}

char	*create_prompt(void)
{
	static char	*username;
	char		*prompt;
	char		*cwd;
	int			len;

	if (!username)
	{
		username = getenv("USER");
		if (!username)
			username = "NOUSERNAME";
	}
	cwd = getcwd(NULL, 0);
	prompt = ft_calloc(sizeof(char), ft_strlen(username) + ft_strlen(cwd) + 5);
	len = ft_strlen(username);
	ft_memcpy(username, prompt, len);
	prompt[len] = '@';
	ft_memcpy(cwd, prompt + ft_strlen(prompt), ft_strlen(cwd));
	ft_memcpy(":> ", prompt + ft_strlen(prompt), 3);
	free(cwd);
	return (prompt);
}
