#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;
	char	*last;

	str = (char *)s;
	i = -1;
	last = NULL;
	while (s[++i])
	{
		if (s[i] == c)
			last = &str[i];
	}
	if (c == 0)
		return (&str[i]);
	return (last);
}
