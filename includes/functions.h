/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:02:55 by aabduvak          #+#    #+#             */
/*   Updated: 2022/06/23 14:41:08 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include <structs.h>

void	cd(t_process *process);
void	env(t_process *process);
void	unset(t_process *process);
void	echo(t_process *process);
void	pwd(t_process *process);
void	export(t_process *process);
void	run_builtin(t_process *process);
int		is_builtin(char *command);

//UTILt_envp	*ft_envpnew(char *str);
t_envp	*construct(char	**envp);
t_envp	*ft_envpnew(char *env_name);
void	ft_envpadd_back(t_envp **lst, t_envp *new);
void	free_list(char **list);
void	ft_envpdelone(t_envp *lst, void (*del) (void *));
void	ft_setenv(t_process *process);
char	*ft_getenv(char *name, t_envp *envl);
char	**deconstruct(t_envp *envl);
char	*get_fullpath(char *path, char *name);
int		ft_envpsize(t_envp *lst);
int		contains_char(char *str, char c);
int		start_process(t_process *process);

#endif
