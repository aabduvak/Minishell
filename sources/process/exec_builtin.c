#include <minishell.h>

int	exec_builtin(t_process *proc)
{
	int	key;

	key = 0;
	if (!ft_strcmp(proc->name, "cd") && ++key)
		cd(proc);
	else if (!ft_strcmp(proc->name, "env") && ++key)
		env(proc);
	else if (!ft_strcmp(proc->name, "unset") && ++key)
		unset(proc);
	else if (!ft_strcmp(proc->name, "echo") && ++key)
		echo(proc);
	else if (!ft_strcmp(proc->name, "pwd") && ++key)
		pwd(proc);
	else if (!ft_strcmp(proc->name, "export") && ++key)
		export(proc);
	else if (!ft_strcmp(proc->name, "exit") && ++key)
		ft_exit(0);
	return (key);
}
