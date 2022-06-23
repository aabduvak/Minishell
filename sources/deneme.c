#include <minishell.h>

int	main(int argc, char **argv, char **envp)
{
	t_stdfd		*stdfd;
	t_process	*process;
	t_redirect	*redirect;

	char		*args[] = {"grep", "ras", NULL};

	process = malloc(sizeof(t_process));
	process->name = "grep";
	process->args = args;
	process->envp = construct(envp);
	process->path = "/usr/bin/grep";

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

	
	/*t_process	*next;
	char		*args2[] = {"cat", NULL};

	next = malloc(sizeof(t_process));
	next->name = "cat";
	next->path = "/bin/cat";
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
	//process->next = next;
//	process = next;
	*/
	printf("status: %i\n", start_process(process));
}
