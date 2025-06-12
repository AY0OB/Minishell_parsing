#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int	main(void)
{
	int fd = open("fic.txt", O_WRONLY | O_CREAT | O_APPEND, 0666);

	int i = 0;

	while (i < 5)
	{
		write(fd, "b", 1);
		i++;
	}
	write(fd, "\n", 1);
	close(fd);
}
