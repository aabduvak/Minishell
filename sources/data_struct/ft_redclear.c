/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdclear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:37:59 by arelmas           #+#    #+#             */
/*   Updated: 2022/07/08 15:40:16 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <data_struct.h>

void	ft_redclear(t_redirect *red)
{
	free(red->read);
	free(red->write);
	free(red->delimeter);
	free(red->overwrite);
}
