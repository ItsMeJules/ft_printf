#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*cd;
	unsigned char	*cs;


	if (!src && !dest)
		return (dest);
	cd = (unsigned char *)dest;
	cs = (unsigned char *)src;
	if (cs < cd)
	{
		while (n--)
			cd[n] = cs[n];
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
