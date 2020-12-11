#include "includes/ft_printf.h"

int	main()
{
	int	res = ft_printf("%sfine and you ? %c\n", "hi how are you", 'u');
	ft_printf("%d", res);
}
