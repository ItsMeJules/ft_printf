/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_converters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 16:12:56 by jules             #+#    #+#             */
/*   Updated: 2020/12/15 15:20:21 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_num(t_helper *helper, long nbr)
{
	if (nbr < 0)
	{
		fill_print(helper, '-');
		nbr *= -1;
	}
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
		write_num(helper, (long)val);
		pad_print(helper);
	}
	else
	{
		pad_print(helper);
		precision_print(helper);
		write_num(helper, (long)val);
	}
}

void	handle_u(t_helper *helper, va_list *list)
{
	unsigned int	val;
	int				digits;

	val = va_arg(*list, unsigned int);
	digits = count_digits(val);
	if (helper->precision > 0)
		helper->pad_len -= helper->precision;
	else
		helper->pad_len -= digits;
	helper->precision -= digits;
	if (!helper->r_pad)
	{
		precision_print(helper);
		write_num(helper, (long)val);
		pad_print(helper);
	}
	else
	{
		pad_print(helper);
		precision_print(helper);
		write_num(helper, (long)val);
	}
}
