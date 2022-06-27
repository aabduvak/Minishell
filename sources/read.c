#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	buf[2555];
	int		readed;
	int		i;

	i = 0;
	readed = 1;
	while (readed)
	{
		printf("%s. input: ", argv[1]);
		readed = read(0, buf, 255);
		buf[readed] = 0;
		printf("%s$\nReaded %i bytes\n", buf, readed);
	}
	return (0);
}
