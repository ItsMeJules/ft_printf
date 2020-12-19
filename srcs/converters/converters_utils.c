/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 21:23:10 by jules             #+#    #+#             */
/*   Updated: 2020/12/19 01:55:10 by jules            ###   ########.fr       */
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
	if (helper->precision > 0)
		helper->pad_len -= helper->precision + 1;
	else
		helper->pad_len -= val < 0 ? digits + 1 : digits;
	helper->precision -= digits;
}
