#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*buffer;
	
	if (!(buffer = malloc(size)))
		return (NULL);
	ft_bzero(buffer, size);
	return (buffer);
}
