#include <minishell.h>

int	main(int argc, char **argv, char **envp)
{
	char	buf[255] = {0};
	int		readed;
	t_cmdlist	*cmd;
	t_cmdlist	*tmp;
	t_envp		*envl;
	t_process 	*proc;
	t_process 	*new_proc;

	while (1)
	{
		write(1, ">>> ", 4);
		readed = read(1, buf, 255);
		/*if (*buf == 4)
			printf("\nctrD\n");*/
		buf[readed - 1] = 0;
		cmd = parse_line(buf);
		tmp = cmd;
		if (!cmd)
			printf("error\n");
		/*for (int i = 1; cmd; cmd = cmd->next, i++)
		{
			printf("%i. {%s}", i, cmd->cmd);
			printf("-> ");
			if (cmd->type == TSTRING)
				printf("string");
			else if (cmd->type == TCOMMAND)
				printf("b-in oper");
			printf("\n");
		}*/
		envl = construct(envp);
		proc = convert(tmp, envl);
		if (!proc)
			printf("converting error\n");
		new_proc = proc;
		/*
		for (int i = 0; proc; proc = proc->next)
		{
			printf("\n-------------------------\n");
			printf("process name: %s\n", proc->name);
			printf("full path: %s\n", proc->path);
			printf("args: ");
			for (int i = 0; proc->args[i]; i++)
				printf("%s ", proc->args[i]);
			printf("\n");
			if (proc->redirect->write)
				printf("redirect to: %s\n", proc->redirect->write);
			if (proc->redirect->read)
				printf("read from: %s\n", proc->redirect->read);
			if (proc->redirect->overwrite)
				printf("overwrite to: %s\n", proc->redirect->overwrite);
			if (proc->redirect->delimeter)
				printf("delimeter with: %s\n", proc->redirect->delimeter);
	
		}
		exit(0);
		*/
		int proc = start_process(new_proc);
		if (proc < 0)
			perror("minishell");
		wait(0);
		printf("proc: %i\n", proc);
	}
}
