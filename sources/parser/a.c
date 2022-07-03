#include <stdio.h>
#include <unistd.h>

int	main()
{
	int	i;

	i = 0;
	while(1)
	{
		usleep(1000);
		printf("%i: %i\n", i / 255 % 2, i % 255);
		i++;
	}
}
