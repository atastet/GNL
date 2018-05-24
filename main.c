#include "get_next_line.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		ret;

	dprintf(1, "M1\n");
	if (argc > 4)
		return (1);
	dprintf(1, "M2\n");
	fd = open(argv[1], O_RDONLY);
	dprintf(1, "M3\n");
	ret = get_next_line(fd, &line);
	dprintf(1, "%d\n", ret);
	ft_putnbr(ret);
	dprintf(1, "m5\n");
	ft_putstr(line);
	return (0);
}
