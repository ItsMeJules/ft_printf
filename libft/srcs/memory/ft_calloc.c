#include "libft.h"

void	*ft_calloc(size_t nmenb, size_t size)
{
	void	*ptr;

	if (!(ptr = malloc(nmenb * size)))
		return (NULL);
	ft_bzero(ptr, nmenb * size);
	return (ptr);
}
