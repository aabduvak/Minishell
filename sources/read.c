#include <unistd.h>
#include <stdio.h>

int	main()
{
	char	buf[2555];
	int		readed;
	int		i;

	i = 0;
	readed = 1;
	while (readed)
	{
		printf("%i. input: ", ++i);
		readed = read(0, buf, 255);
		buf[readed - 1] = 0;
		printf("%s$\n", buf);
		printf("%i. line writed\n", i);
	}
	printf("program closed\n");
	return (0);
}
