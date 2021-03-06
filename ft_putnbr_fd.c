#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * (-1);
	}
	else
	{
		if (n > 0)
		{
			if (n / 10 == 0)
			{
				ft_putchar_fd(n % 10 + '0', fd);
				return ;
			}
			ft_putnbr_fd(n / 10, fd);
			ft_putchar_fd(n % 10 + '0', fd);
		}
	}
	else
		if (n == 0)
			ft_putchar_fd('0', fd);
}
