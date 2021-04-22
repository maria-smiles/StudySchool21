#include <stdlib.h>
#include "libft.h"

char **ft_split(char const *s, char c)
{
	unsigned int i;
	unsigned int n;
	unsigned int j;
	unsigned int len;
	unsigned int slen;
	char *p_beg;
	char *p_end;
	char **p;

	slen = ft_strlen(s);
	i = 0;
	p = malloc(sizeof(s)*(ft_strlen(s)+1));
	n = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			n++;			//знаем, сколько раз встречается делитель
			i++;
		}
		else
			i++;
	}
	p = malloc (sizeof(p)*(n+2));
	i = 0;
	n = 0;
	j = 0;
	while (i < slen)
	{
		if(s[i] != c)
		{
			p[0] = (char *)&s[i];
			break;						//Поставили самый первый указатель
		}
		i++;
	}
	i = 0;
	while(i < slen)
	{
		if (s[i] == c)
		{
			len = i-n;
			n = i+1;
		}
		i++;
	}
	if (n == 0)
	{
		p[0] = (char *) &s[0];
		p[1] = (char *) '\0';
	}

}
