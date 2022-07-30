/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 03:08:05 by arelmas           #+#    #+#             */
/*   Updated: 2022/07/31 01:19:29 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_STRUCT_H
# define DATA_STRUCT_H

# include <structs.h>

t_cmdlist	*ft_cmdnew(char *cmd, int type);

void		ft_cmdadd_back(t_cmdlist **cmdlist, t_cmdlist *new);
void		*ft_cmdclear(t_cmdlist **cmdlist, void (*del)(void *));

#endif
