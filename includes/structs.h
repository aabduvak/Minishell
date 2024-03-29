/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 05:51:22 by aabduvak          #+#    #+#             */
/*   Updated: 2022/08/08 15:48:03 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdlib.h>
# include <../libft/sources/libft.h>

# define STR_I 2
# define CHR_I 255
# define TSTRING 0
# define TCOMMAND 1
# define TENV 2

typedef enum e_red {
	NOPE = 0,
	READ = 1,
	WRITE = 2,
	DELIMETER = 4,
	OVERWRITE = 8
}	t_red;

typedef struct s_cmdlist {
	char				*cmd;
	int					type;
	int					piece;
	int					cur_tp;
	struct s_cmdlist	*next;
}	t_cmdlist;

typedef struct s_parser {
	int			type;
	t_cmdlist	*list;
}	t_parser;

typedef struct s_redirect {
	char	*read;
	char	*write;
	char	*overwrite;
	t_list	*delimeter;
}	t_redirect;

typedef struct s_stdfd {
	int	_stdin;
	int	_stdout;
	int	_stderr;
}	t_stdfd;

typedef struct s_envp
{
	char			*key;
	char			*value;
	char			*fullstr;
	struct s_envp	*next;
}	t_envp;

typedef struct s_process
{
	pid_t				pid;
	char				*name;
	char				*path;
	char				**args;
	t_envp				*envp;
	t_stdfd				*stdfd;
	t_redirect			*redirect;
	struct s_process	*next;
	struct s_process	*prev;
}						t_process;

#endif
