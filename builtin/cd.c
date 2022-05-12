/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD:includes/macro.h
/*   By: aabduvak <aabduvak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:42:35 by aabduvak          #+#    #+#             */
/*   Updated: 2022/05/12 03:19:02 by aabduvak         ###   ########.fr       */
=======
/*   By: arelmas <arelmas@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 01:25:16 by arelmas           #+#    #+#             */
/*   Updated: 2022/05/12 01:25:36 by arelmas          ###   ########.fr       */
>>>>>>> main_arbi:builtin/cd.c
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

<<<<<<< HEAD:includes/macro.h
# define SUCCESS 0
# define FAILED 1
# define ERROR -1

#endif
=======
void	cd(char *path)
{
	if (chdir(path) == -1)
		perror("cd");
}
>>>>>>> main_arbi:builtin/cd.c
