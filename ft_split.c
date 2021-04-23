#include <stdlib.h>
#include "libft.h"

char **ft_split(char const *s, char c)
{
	char *begin;
	int i;
	int count;
	char **dst;
	int j;
	int k;
	int num;

	while(s[i] == c)
		i++;
	if (s[i] != '\0')
		begin = (char *) &s[i];
	else
		return ((char **)'\0');
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
	dst = malloc(sizeof(dst) * (count+1));
	if (!dst)
		return ((char **)'\0');
	num = 0;
	j = 0;
	k = 0;
	i = 0;
	while (begin[i] != '\0')
	{
		if(begin[i] != c)
			num++;
		else
			if (begin[i] == c && begin[i-1] != c)
			{
				dst[j] = malloc(sizeof(dst[j])*(num + 1));
				if (!dst[j])
					free(dst);
				while(k < num)
				{
					dst[j][k] = begin[i-num+k];
					k++;
				}
			}
			else
				if (begin[i] == c && begin[i-1] == c)
				{
					dst[j][k] = '\0';
					j++;
					num = 0;
					k = 0;
				}
		i++;
	}
	dst[count] = malloc(sizeof(dst[count]) * 1);
	if (!dst[count])
		free(dst);
	dst[count][0] = '\0';
	return (dst);
}
