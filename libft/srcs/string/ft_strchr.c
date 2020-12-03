#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = -1;
	while (s[++i])
	{
		if (s[i] == c)
			return (&str[i]);
	}
	if (c == 0)
		return (&str[i]);
	return (NULL);
}
