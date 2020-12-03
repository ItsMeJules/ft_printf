#include "libft.h"

size_t	ft_strlcpy(char *dest, char const *src, size_t size)
{
	size_t	srclen;

	srclen = ft_strlen(src);
	if (size != 0)
	{
		while (*src && --size)
			*dest++ = *src++;
		*dest = 0;
	}
	return (srclen);
}
