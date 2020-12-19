/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 22:59:52 by jules             #+#    #+#             */
/*   Updated: 2020/12/19 22:25:08 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_star(t_helper *helper, char c, va_list *list)
{
	int val;

	val = va_arg(*list, int);
	if (c == '%' && val != 0)
	{
		helper->pad_char = ' ';
		helper->r_pad = val > 0;
		helper->pad_len = ft_abs(val);
	}
	else if (c == '.' && val > 0)
		helper->precision = val;
	else if (c == '0')
	{
		if (val > 0)
			helper->pad_char = '0';
		else if (val < 0)
			helper->r_pad = 0;
		helper->pad_len = val;
	}
}

void	handle_flags(t_helper *helper, va_list *list, char c)
{
	if (c == '*')
		handle_star(helper, helper->str[helper->i - 1], list);
	else if (c == '-')
		handle_pad(helper, 0, list);
	else if (c == '0')
		handle_zero_pad(helper, list);
	else if (ft_isdigit(c))
		handle_pad(helper, 1, list);
	else if (c == '.')
		handle_precision(helper, list);
}
