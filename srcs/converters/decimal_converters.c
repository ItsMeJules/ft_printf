/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_converters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 16:12:56 by jules             #+#    #+#             */
/*   Updated: 2020/12/20 10:23:09 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_num(t_helper *helper, long nbr)
{
	if (nbr == 0 && helper->precision == 0)
		return ;
	if (nbr < 0)
	{
		if (helper->r_pad && helper->pad_char == ' ')
			pad_print(helper);
		fill_print(helper, '-');
		if (helper->r_pad && helper->pad_char == '0')
			pad_print(helper);
		precision_print(helper);
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
	prec_pad_checks(helper, val, digits);
	if (!helper->r_pad)
	{
		if (val >= 0)
			precision_print(helper);
		write_num(helper, (long)val);
		pad_print(helper);
	}
	else
	{
		if (val >= 0)
		{
			pad_print(helper);
			precision_print(helper);
		}
		write_num(helper, (long)val);
	}
}

void	handle_u(t_helper *helper, va_list *list)
{
	unsigned int	val;
	int				digits;

	val = va_arg(*list, unsigned int);
	digits = count_digits(val);
	prec_pad_checks(helper, val, digits);
	if ((int)val < 0)
		helper->pad_len++;
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

void	write_hex(t_helper *helper, char *hexa, unsigned int val)
{
	if (val == 0)
	{
		if (helper->precision == 0)
			return ;
		fill_print(helper, '0');
	}
	while (*hexa)
		fill_print(helper, *hexa++);
}

void	handle_x(t_helper *helper, va_list *list, int maj)
{
	unsigned int	val;
	char			*hexa;
	int				length;

	val = va_arg(*list, unsigned int);
	hexa = to_base(val, (maj ? "0123456789ABCDEF" : "0123456789abcdef"));
	length = ft_strlen(hexa);
	prec_pad_checks(helper, val, length);
	if ((int)val < 0)
		helper->pad_len++;
	if (!helper->r_pad)
	{
		precision_print(helper);
		write_hex(helper, hexa, val);
		pad_print(helper);
	}
	else
	{
		pad_print(helper);
		precision_print(helper);
		write_hex(helper, hexa, val);
	}
}
