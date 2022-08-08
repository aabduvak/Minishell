/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:37:59 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/09 00:31:33 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_redclear(t_redirect *red)
{
	if (red->read)
		free(red->read);
	if (red->write)
		free(red->write);
	if (red->delimeter)
		ft_lstclear(&red->delimeter, free);
	if (red->overwrite)
		free(red->overwrite);
	free(red);
}
