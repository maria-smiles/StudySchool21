#include "libft.h"

void ft_putendl_fd(char *s, int fd)
{
	write(fd, s, (sizeof(s)*ft_strlen(s)));
	write(fd, '\n', 1);
}
