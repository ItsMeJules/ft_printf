#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	
	if (!(dup = ft_strnew(ft_strlen(s))))
		return (NULL);
	return (ft_strcpy(dup, (char*)s));
}
