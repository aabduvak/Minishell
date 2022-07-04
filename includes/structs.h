/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 05:51:22 by aabduvak          #+#    #+#             */
/*   Updated: 2022/07/05 01:07:13 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdlib.h>
# include <../libft/sources/libft.h>

#define STR_I 2
#define CHR_I 255
#define GET_STR_I(index) index / CHR_I % STR_I
#define GET_CHR_I(index) index % (CHR_I - 1)

typedef enum e_red {
	NOPE = 0,
	READ = 1,
	WRITE = 2,
	DELIMETER = 4,
	OVERWRITE = 8
}	t_red;

typedef struct s_redirect {
	char	*name;
	t_red	type;
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
