/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:02:55 by aabduvak          #+#    #+#             */
/*   Updated: 2022/05/12 12:03:56 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include <libft.h>

void	cd(char *path);
void	env(t_list *lst);
int		unset(t_list *lst, char *name);
void	echo(char *str, int flag);
void	pwd(void);

//UTILS

void	ft_setenv(char *var_name, char *value, t_list *envl);
char	*ft_getenv(char *name, t_list *envl);
t_list	*construct(char	**envp);
char	**deconstruct(t_list *envl);

#endif
