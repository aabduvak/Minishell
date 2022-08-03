/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:37:59 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/03 17:15:28 by arelmas          ###   ########.fr       */
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
		free(red->delimeter);
	if (red->overwrite)
		free(red->overwrite);
	free(red);
}
