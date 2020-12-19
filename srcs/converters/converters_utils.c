/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 21:23:10 by jules             #+#    #+#             */
/*   Updated: 2020/12/19 17:46:16 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pad_print(t_helper *helper)
{
	while (helper->pad_len > 0)
	{
		fill_print(helper, helper->pad_char);
		helper->pad_len--;
	}
}

void	precision_print(t_helper *helper)
{
	while (helper->precision > 0)
	{
		fill_print(helper, '0');
		helper->precision--;
	}
}

void	prec_pad_checks(t_helper *helper, int val, int digits)
{
	if (helper->precision > 0 && digits < helper->precision)
		helper->pad_len -= helper->precision + (val < 0 ? 1 : 0);
	else
	{
		if (val < 0)
			helper->pad_len -= digits + 1;
		else if (val > 0)
			helper->pad_len -= digits;
		else if (helper->precision != 0)
			helper->pad_len--;
	}
	helper->precision -= digits;
}
