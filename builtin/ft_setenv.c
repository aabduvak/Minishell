/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 03:16:32 by arelmas           #+#    #+#             */
/*   Updated: 2022/06/08 05:49:38 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_setenv(char *var_name, char *value, t_list *envl)
{
	char	*tmp;
	char	*env_res;

	if (!var_name || !value || !*var_name)
		return ;
	unset(envl, var_name);
	tmp = ft_strjoin(var_name, "=");
	env_res = ft_strjoin(tmp, value);
	ft_lstadd_back(&envl, ft_lstnew(env_res));
	free(tmp);
}
