/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 20:49:07 by aabduvak          #+#    #+#             */
/*   Updated: 2022/08/08 23:41:50 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clearsignals(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

void	connectsignals(void)
{
	signal(SIGINT, signalhandler);
	signal(SIGQUIT, SIG_IGN);
}

void	signalhandler(int sig)
{
	(void)sig;
	rl_on_new_line();
	rl_replace_line("", 0);
	printf("\n");
	rl_redisplay();
}

void	del_handler(int sig)
{
	if (sig != SIGINT)
		return ;
	close(0);
}

void	nothing(int sig)
{
	(void)sig;
	printf("\n");
	return ;
}
