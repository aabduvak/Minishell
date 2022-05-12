#ifndef BUILTIN_H
# define BUILTIN_H

#include <libft.h>

void	cd(char *path);
void	env(t_list *lst);
int		unset(t_list *lst, char *name);
void	echo(char *str, int flag); 
void	pwd();
//UTILS
void	ft_setenv(char *var_name, char *value, t_list *envl);
char	*ft_getenv(char *name, t_list *envl);

#endif
