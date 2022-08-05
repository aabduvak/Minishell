/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:02:55 by aabduvak          #+#    #+#             */
/*   Updated: 2022/08/05 10:25:57 by arelmas          ###   ########.fr       */
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
void		ft_exit(t_process *process);
void		run_builtin(t_process *process);
int			is_builtin(char *command);

//UTILt_envp	*ft_envpnew(char *str);
t_envp		*construct(char	**envp);
t_envp		*ft_envpnew(char *env_name);
void		ft_envpadd_back(t_envp **lst, t_envp *new);
void		free_list(char **list);
void		ft_update_status(int status, t_process *process);
void		ft_envpdelone(t_envp *lst, void (*del) (void *));
void		ft_setenv(t_process *process);
void		ft_update_envp(char *key, char *value, t_envp *envl);
char		*ft_getenv(char *name, t_envp *envl);
char		**deconstruct(t_envp *envl);
char		*get_fullpath(char *path, char *name);
int			ft_envpsize(t_envp *lst);
int			contains_char(char *str, char c);
int			is_relatedbuiltin(char *name);

//PROCESS
int			red_read(const char *file_name);
int			red_write(const char *file_name);
int			red_overwrite(const char *file_name);
int			red_delimeter(t_list *del, int read_red);
int			exec_builtin(t_process *proc);
int			start_process(t_process *process);
int			proc_access(char *name);
int			run_related_builtins(t_process *process, int pipes[2]);
int			child(t_process *process, int pipes[2]);
void		parent(t_process *process);
void		set_stdfd(t_process *process, int pipes[2]);
int			initfd(t_process *process, int pipes[2]);

//PARSER
t_process	*convert(t_cmdlist *cmd, t_envp *evnl);
t_cmdlist	*parse_line(char *str);
t_cmdlist	*combinate_quote(t_cmdlist *cmd);
void		parse_env(t_cmdlist *cmd, t_envp *envl);
char		*parse_quote(t_cmdlist **list, char buf[STR_I][CHR_I],
				char *line, int index);
char		*buf_over(t_cmdlist **list, char buf[STR_I][CHR_I],
				char *line, int index);
char		*parse_bop(t_cmdlist **list, char buf[STR_I][CHR_I],
				char *line, int index);
char		*ft_rdpipe(t_cmdlist **list, char buf[STR_I][CHR_I],
				char *line, int index);
char		*ft_rdread(t_cmdlist **list, char buf[STR_I][CHR_I],
				char *line, int index);
char		*jump_space(char *str);
char		*ft_parse_cmd(char *line, t_envp *envl);
int			is_endcmd(char c);
int			ft_check_letter(char c);
int			ft_check_first_letter(char c);
int			check_built_op(char *str);
int			check_env(char *env_name);
int			find_env(char *line, int quote);
int			ft_envline_len(char *line, t_envp *envl);
int			ft_getenv_val(char *line, char *src, size_t *idx, t_envp *envl);
size_t		ft_get_buflen(char strings[STR_I][CHR_I], size_t len);
size_t		ft_parse_len(char *input, int *env_idx, size_t params_len, t_envp *envl);
char		*strings_join(char strings[STR_I][CHR_I], size_t len);
char		*ft_parse_u(t_parser *data, char buf[STR_I][CHR_I], char *line, int *index);
void		envcpy(char *dst, char *src, size_t size);
void		strings_bzero(char strings[STR_I][CHR_I], size_t count, size_t len);
void		end_block(t_cmdlist **list, char buf[STR_I][CHR_I], int type, int index);
size_t		ft_get_linelen(t_envp *envl, char *input);
char		*ft_rdwrite(t_cmdlist **list, char buf[STR_I][CHR_I], char *line, int index);

//STRUCTS
void		ft_envpclear(t_envp *envl);
void		ft_redclear(t_redirect *red);
void		ft_write_restart(t_process *proc, char **dst, char *src);
void		ft_read_restart(t_process *proc, char **dst, char *src);
void		ft_procinit(t_process *proc, t_envp *envl);
void		ft_proclear(t_process **proc, void (*del)(void *));
void		*ft_procadd_back(t_process **proc, t_process *new);
t_process	*ft_procnew(t_cmdlist *cmd, t_envp *envl);

//SIGNALS
void		clearsignals(void);
void		connectsignals(void);
void		signalhandler(int sig);

//PROMPT
char		*get_input(void);
char		*create_prompt(void);

//ERROR
int			ft_error(t_process *process, int status);

#endif
