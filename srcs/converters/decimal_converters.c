/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_converters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 16:12:56 by jules             #+#    #+#             */
/*   Updated: 2020/12/15 14:58:00 by jules            ###   ########.fr       */
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
	if (helper->precision > 0)
		helper->pad_len -= helper->precision;
	else
		helper->pad_len -= digits;
	helper->precision -= digits;
	if (!helper->r_pad)
	{
		precision_print(helper);
		write_num(helper, val);
		pad_print(helper);
	}
	else
	{
		pad_print(helper);
		precision_print(helper);
		write_num(helper, val);
	}
}
