/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:02:55 by aabduvak          #+#    #+#             */
/*   Updated: 2022/07/18 21:06:11 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include <structs.h>
# include <data_struct.h>

# define STR_I 2
# define CHR_I 255
# define GET_STR_I(index) index / CHR_I % STR_I
# define GET_CHR_I(index) index % (CHR_I - 1)

void		cd(t_process *process);
void		env(t_process *process);
void		unset(t_process *process);
void		echo(t_process *process);
void		pwd(t_process *process);
void		export(t_process *process);
void		ft_exit(int status);
void		run_builtin(t_process *process);
int			is_builtin(char *command);

//UTILt_envp	*ft_envpnew(char *str);
t_envp		*construct(char	**envp);
t_envp		*ft_envpnew(char *env_name);
void		ft_envpadd_back(t_envp **lst, t_envp *new);
void		free_list(char **list);
void		ft_envpdelone(t_envp *lst, void (*del) (void *));
void		ft_setenv(t_process *process);
char		*ft_getenv(char *name, t_envp *envl);
char		**deconstruct(t_envp *envl);
char		*get_fullpath(char *path, char *name);
int			ft_envpsize(t_envp *lst);
int			contains_char(char *str, char c);

//process
int			red_read(const char *file_name);
int			red_write(const char *file_name);
int			red_overwrite(const char *file_name);
int			red_delimeter(const char *del);
int			exec_builtin(t_process *proc);
int			start_process(t_process *process);

//PARSER
t_process	*convert(t_cmdlist *cmd, t_envp *evnl);
t_cmdlist	*parse_line(char *str);
char		*parse_quote(t_cmdlist **list, char buf[STR_I][CHR_I],
				char *line, int index);
char		*buf_over(t_cmdlist **list, char buf[STR_I][CHR_I],
				char *line, int index);
char		*parse_bop(t_cmdlist **list, char buf[STR_I][CHR_I],
				char *line, int index);
char		*jump_space(char *str);
int			is_endcmd(char c);
int			check_built_op(char *str);
char		*strings_join(char strings[STR_I][CHR_I], size_t len);
void		strings_bzero(char strings[STR_I][CHR_I], size_t count, size_t len);

//STRUCTS
void		ft_envpclear(t_envp *envl);
void		ft_redclear(t_redirect *red);
void		ft_procinit(t_process *proc, t_envp *envl);
void		*ft_procadd_back(t_process **proc, t_process *new);
t_process	*ft_procnew(t_cmdlist *cmd, t_envp *envl);

//SIGNALS
void		clearsignals(void);
void		connectsignals(void);
void		signalhandler(int sig);

//PROMPT
char		*get_input(void);
char		*create_prompt(void);

#endif
