/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_converters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 16:12:56 by jules             #+#    #+#             */
/*   Updated: 2020/12/07 21:26:40 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_num(t_helper *helper, long num)
{
	if (num > -10 && num < 10)
	{
		if (num < 0)
		{
			fill_print(helper, '-');
			num = -num;
		}
		fill_print(helper, num + '0');
	}
	else if (nb > 0)
	{
		write_num(num / 10);
		write_num(num % 10);
	}
	else
	{
		fill_print(helper, '-');
		write_num(-num);
	}
}

int	handle_d(t_helper *helper, va_list *list)
{
	int	val;
	int	digits;

	val = va_arg(*list, int);
	digits = count_digits(val);
	helper->precision -= digits;
	helper->pad_len -= digits;
	write_padding(helper, 1);
	write_num((long)val);
}
