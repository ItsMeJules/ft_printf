/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 22:49:43 by jules             #+#    #+#             */
/*   Updated: 2020/12/19 18:30:13 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_digits(long nb)
{
	int	digits;

	digits = 0;
	while (nb)
	{
		nb /= 10;
		digits++;
	}
	return (digits);
}
char	*to_base(unsigned long nbr, char *base)
{
	static char buffer[50];
	char		*ptr;
	int			base_len;

	ptr = &buffer[49];
	*ptr = 0;
	if (nbr == 0)
		*--ptr = 0;
	base_len = ft_strlen(base);
	while (nbr != 0)
	{
		*--ptr = base[nbr % base_len];
		nbr /= base_len;
	}
	return (ptr);
}
