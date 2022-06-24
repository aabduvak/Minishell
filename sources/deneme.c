#include <minishell.h>

int	main(int argc, char **argv, char **envp)
{
	t_stdfd		*stdfd;
	t_process	*process;
	t_redirect	*redirect;

	char		*args[] = {"ls", NULL};

	process = malloc(sizeof(t_process));
	process->name = "ls";
	process->args = args;
	process->envp = construct(envp);
	process->path = "/bin/ls";

	stdfd = malloc(sizeof(t_stdfd));
	stdfd->_stdin = 0;
	stdfd->_stdout = 1;
	stdfd->_stderr = 2;
	process->stdfd = stdfd;

	redirect = malloc(sizeof(t_redirect));
	redirect->type = NOPE;
	process->redirect = redirect;
	process->next = NULL;
	process->prev = NULL;

	t_process	*next;
	char		*args2[] = {"read", NULL};

	next = malloc(sizeof(t_process));
	next->name = "read";
	next->path = "/Users/arelmas/myPlace/minishell2/sources/read";
	next->args = args2;
	next->envp = construct(envp);
	
	stdfd = malloc(sizeof(t_stdfd));
	stdfd->_stdin = 0;
	stdfd->_stdout = 1;
	stdfd->_stderr = 2;
	next->stdfd = stdfd;
	
	redirect = malloc(sizeof(t_redirect));
	redirect->type = NOPE;
	next->redirect = redirect;
	next->next = NULL;
	next->prev = process;
	process->next = next;

	t_process	*tmp;
//
/*
	tmp = next;
	next = malloc(sizeof(t_process));
	next->name = "cat";
	next->path = "/bin/cat";
	next->args = args2;
	next->envp = construct(envp);
	
	stdfd = malloc(sizeof(t_stdfd));
	stdfd->_stdin = 0;
	stdfd->_stdout = 1;
	stdfd->_stderr = 2;
	next->stdfd = stdfd;
	
	redirect = malloc(sizeof(t_redirect));
	redirect->type = NOPE;
	next->redirect = redirect;
	next->next = NULL;
	next->prev = tmp;
	tmp->next = next;
	*/
//
/*
	tmp = next;
	next = malloc(sizeof(t_process));
	next->name = "cat";
	next->path = "/bin/cat";
	next->args = args2;
	next->envp = construct(envp);
	
	stdfd = malloc(sizeof(t_stdfd));
	stdfd->_stdin = 0;
	stdfd->_stdout = 1;
	stdfd->_stderr = 2;
	next->stdfd = stdfd;
	
	redirect = malloc(sizeof(t_redirect));
	redirect->type = NOPE;
	next->redirect = redirect;
	next->next = NULL;
	next->prev = tmp;
	tmp->next = next;
*/
	printf("status: %i\n", start_process(process));
	return (0);
}
