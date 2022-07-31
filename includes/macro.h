/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 04:17:34 by aabduvak          #+#    #+#             */
/*   Updated: 2022/07/31 05:12:41 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H

# define SUCCESS 0
# define FAILED 1
# define ERROR -1

# define FT_TRUE 1
# define FT_FALSE 0

// Error codes

# define ER_NOTPERMITTED 1
# define ER_NOPROC 3
# define ER_EXEC 126
# define ER_RUNPROC -1
# define ER_NOCOMM 127
# define ER_STEXIT 128
# define ER_CTRLC 130
# define ER_STOUT 255
# define ER_NOFILE 2
# define ER_ACCES 13
# define ER_PIPES 32
# define ER_ISDIR 21
# define ER_NOTDIR 20
# define ER_TIMEDOUT 110
# define ER_CONNREFUSED 111

// Error Messages

# define E_NOTPERMITTED "divide by 0 or operation not permitted"
# define E_EXEC "command invoked cannot execute"
# define E_NOCOMM "command not found"
# define E_STEXIT "invalid argument to exit"
# define E_CTRLC "script terminated by Control-C"
# define E_STOUT "exit status out of range"
# define E_NOPROC "no such process"
# define E_NOFILE "no such file or directory"
# define E_ACCES "permission denied"
# define E_PIPES "broken pipe"
# define E_ISDIR "is a directory"
# define E_NOTDIR "not a directory"
# define E_TIMEDOUT "connection timed out"
# define E_CONNREFUSED "connection refused"
# define E_RUNPROC "error occured while running process"

// Builtins

# define BT_EXIT "exit"
# define BT_ECHO "echo"
# define BT_UNSET "unset"
# define BT_WHERE "where"
# define BT_EXPORT "export"
# define BT_PWD "pwd"
# define BT_ECHO "echo"
# define BT_CD "cd"
# define BT_ENV "env"

#endif
