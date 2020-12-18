#include <stdio.h>
#include "includes/ft_printf.h"

int	main()
{
	int	i = 5;
	int	*d = &i;
	int	j = 1234;

	ft_printf("%30p %.5x %-10X\n", d, j, j); 
	printf("%30p %.5x %-10X\n", d, j, j);
}
