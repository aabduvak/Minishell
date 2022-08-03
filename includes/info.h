/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:09:49 by aabduvak          #+#    #+#             */
/*   Updated: 2022/08/03 16:53:34 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_H
# define INFO_H

# include <fcntl.h>

# define VERSION "--version"
# define UPDATE "--update"
# define HELP "--help"
# define AUTHOR "--author"

void	show_info(int argc, char **argv);

#endif