#include "libft.h"

void ft_putendl_fd(char *s, int fd)
{
	char endl;

	endl = '\n';
	ft_putstr_fd(s, fd);
	write(fd, &endl, 1);
}
