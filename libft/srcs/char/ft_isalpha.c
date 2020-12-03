#include "libft.h"

int	ft_islower(int c);
int	ft_isupper(int c);

int ft_isalpha(int c)
{
	return (ft_islower(c) || ft_isupper(c));
}
