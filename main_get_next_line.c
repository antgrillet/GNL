#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("testfile.txt", O_RDONLY);
	/*printf("%d", fd);*/
	str = get_next_line(fd);
	printf("%s\n", str);
	str = get_next_line(fd);
	printf("%s", str);
	close(fd);
	free(str);
	return(0);
}
