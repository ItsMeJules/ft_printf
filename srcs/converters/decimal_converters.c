/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_converters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 16:12:56 by jules             #+#    #+#             */
/*   Updated: 2020/12/11 18:19:54 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_num(t_helper *helper, int nb)
{
	unsigned int	nbr;

	if (nb < 0)
	{
		fill_print(helper, '-');
		nbr = (unsigned int)(nb * -1);
	}
	else
		nbr = (unsigned int)nb;
	if (nbr >= 10)
		write_num(helper, nbr / 10);
	fill_print(helper, (char)(nbr % 10 + '0'));
}

void	handle_d(t_helper *helper, va_list *list)
{
	int	val;
	int	digits;

	val = va_arg(*list, int);
	digits = count_digits(val);
	helper->precision -= digits;
	helper->pad_len -= digits;
	write_padding(helper, 1);
	write_num(helper, val);
}
