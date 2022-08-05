/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:09:49 by aabduvak          #+#    #+#             */
/*   Updated: 2022/08/05 02:48:00 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_H
# define INFO_H

# include <fcntl.h>

# define VERSION "--version"
# define HELP "--help"
# define AUTHOR "--author"

void	show_info(int argc, char **argv);

#endif