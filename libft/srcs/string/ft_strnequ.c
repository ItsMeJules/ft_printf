#include "libft.h"

int	ft_strnequ(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!s1 || !s2)
		return (0);
	i = -1;
	while (++i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (0);
	}
	return (1);
}
