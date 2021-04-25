#include "libft.h"

static int	ft_count(const char *s, char c, int i)
{
    int count;
    
    count = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c) && (i == 0 || (s[i - 1] == c)))
		{
			count += 1;
			i++;
		}
		else
			i++;
	}
    return (count);
}

static void	ft_setstr(char *begin, int i, int num, char c, char **dst)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (begin[i] != '\0')
	{
		if (begin[i] != c)
			num++;
		else if (begin[i] == c && begin[i - 1] != c)
			{
				dst[j] =  malloc(sizeof(char) * (num + 1));
              //  if (!dst[j])
                //    ft_free(dst);//function free
				while (k < num)
				{
					dst[j][k] = begin[i - num + k];
					k++;
				}
                dst[j][k] = '\0';
                k = 0;
                num = 0;
                j++;
			}
        else if (begin[i] == c && begin[i - 1] == c)
            {
                i++;
                continue;
            }
        i++;
    }
}

char	**ft_split(char const *s, char c)
{
	char	*begin;
	int		i;
	int		count;
	char	**dst;
	int		num;

	i = 0;
	while (s[i] == c)
		i++;
	if (s[i] != '\0')
		begin = (char *) &s[i];
	else
		return (NULL);
	count = ft_count(s, c, i);
	dst = malloc(sizeof(char *) * (count + 1));
	num = 0;
	i = 0;
	ft_setstr(begin, i, num, c, dst);
    dst[count]= NULL;
	return (dst);
}
