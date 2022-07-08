#include <minishell.h>

int	main(int argc, char **argv, char **envp)
{
	char	buf[255] = {0};
	int		readed;
	t_cmdlist	*cmd;
	t_cmdlist	*tmp;

	readed = read(1, buf, 255);
	buf[readed - 1] = 0;
	cmd = parse_line(buf);
	tmp = cmd;
	if (!cmd)
		printf("error\n");
	for (int i = 1; cmd; cmd = cmd->next, i++)
	{
		printf("%i. {%s}", i, cmd->cmd);
		printf("-> ");
		if (cmd->type == TSTRING)
			printf("string");
		else if (cmd->type == TCOMMAND)
			printf("b-in oper");
		printf("\n");
	}
	t_envp		*envl = construct(envp);
	t_process 	*proc = convert(tmp, envl);
	if (!proc)
		printf("converting error\n");
	for (int i = 0; proc; proc = proc->next)
	{
		printf("\n-------------------------\n");
		printf("process name: %s\n", proc->name);
	}
}
