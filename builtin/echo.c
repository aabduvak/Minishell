/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 01:37:14 by aabduvak          #+#    #+#             */
/*   Updated: 2022/05/12 11:42:54 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	echo(char *str, int flag)
{
	if (flag)
		printf("%s", str);
	else
		printf("%s\n", str);
}

static void	helper(char **argv, int argc, int i)
{
	while (i < argc - 1)
	{
		echo(argv[i], 1);
		echo(" ", 1);
		i++;
	}
	echo(argv[i], 1);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
		printf("\n");
	else if (!ft_strncmp(argv[i], "-n", ft_strlen(argv[i])))
		helper(argv, argc, ++i);
	else
	{
		helper(argv, argc, i);
		printf("\n");
	}
	return (SUCCESS);
}
