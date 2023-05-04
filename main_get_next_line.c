#include "get_next_line.h"

int	main(void)
{
	int fd;

	fd = open("testfile.txt", O_RDONLY);
	printf("%d", fd);
	get_next_line(fd);
	close(fd);
	return(0);
}