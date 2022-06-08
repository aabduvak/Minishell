/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:02:55 by aabduvak          #+#    #+#             */
/*   Updated: 2022/06/08 05:36:32 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include <libft.h>
# include <structs.h>

void	cd(char *path);
void	env(t_process *process);
int		unset(t_list *lst, char *name);
void	echo(char *str, int flag);
void	pwd(void);
void	export(t_process *process);

//UTILS

void	ft_setenv(char *var_name, char *value, t_list *envl);
char	*ft_getenv(char *name, t_list *envl);
t_list	*construct(char	**envp);
char	**deconstruct(t_list *envl);
char	*get_fullpath(char *path, char *name);
int		file_checker(char *path, char *name);
int		is_builtin(char *command);
int		contains_char(char *str, char c);
void	free_list(char **list);

#endif
