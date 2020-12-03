#include "libft.h"

char	*ft_strncpy(char *dest, char *src, size_t len)
{
	size_t	i;

	i = -1;
	while (++i < len && src[i])
		dest[i] = src[i];
	while (i < len)
		dest[i++] = 0;
	return (dest);
}
