#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	char	*new;
	int		i;

	str = (char*)s;
	if (!(new = ft_strnew(ft_strlen(str))))
		return (NULL);
	i = 0;
	while (*str)
	{
		new[i] = f(i, *str++);
		i++;
	}
	new[i] = 0;
	return (new);
}

