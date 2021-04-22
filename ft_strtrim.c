#include <stdlib.h>
#include "libft.h"

static int ft_chrfind(char s, char const *set)
{
	int i;
	int res;

	while (set)
	{
		if (s == set)
			res = 1;
		else
			res = 0;
		set ++;
	}
}

static char *ft_makestr(char *newstr, char *p_beg, char *p_end)
{
int i;

i = 0;
while (p_beg <= p_end)
{
newstr[i] = *p_beg;
i++;
p_beg++;
}
newstr[i] = '\0';
return (newstr);
}

char *ft_strtrim(char const *s1, char const *set)
{
	unsigned int len;
	char *p_beg;
	char *p_end;
	unsigned  int i;
	char *newstr;

	i = 0;
	len = ft_strlen(s1);
	while(ft_chrfind(s1[i], set))
	{
		i++;
	}
	p_beg = &s1[i];
	i = 0;
	while(ft_chrfind(s1[len-i-1], set))
	{
		i++;
	}
	p_end = &s1[len-i-1];

	newstr = malloc(sizeof(s1) * (p_end - p_beg + 2));
	i = 0;
	newstr = ft_makestr(newstr, p_beg, p_end);
	return (newstr);
}