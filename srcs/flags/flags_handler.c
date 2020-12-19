/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 19:37:54 by jules             #+#    #+#             */
/*   Updated: 2020/12/20 00:11:33 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_pad(t_helper *helper, int rpad, va_list *list)
{
	helper->pad_len = 0;
	helper->r_pad = rpad;
	if (!rpad)
		helper->i++;
	if (helper->str[helper->i] == '*')
	{
		helper->pad_len = va_arg(*list, int);
		if (helper->pad_len < 0 && helper->pad_char == '0')
		{
			helper->pad_char = ' ';
			helper->r_pad = 0;
		}
		helper->pad_len = ft_abs(helper->pad_len);
		return ;
	}
	while (ft_isdigit(helper->str[helper->i]))
	{
		helper->pad_len = helper->pad_len * 10 + helper->str[helper->i] - '0';
		helper->i++;
	}
	helper->i--;
}

void	handle_zero_pad(t_helper *helper, va_list *list)
{
	helper->pad_char = '0';
	helper->i++;
	handle_pad(helper, 1, list);
}

void	handle_precision(t_helper *helper, va_list *list)
{
	helper->precision = 0;
	helper->i++;
	if (helper->str[helper->i] == '*')
	{
		helper->precision = va_arg(*list, int);
		if (helper->precision >= 0 && helper->pad_char == '0')
			helper->pad_char = ' ';
		return ;
	}
	while (ft_isdigit(helper->str[helper->i]))
	{
		helper->precision = helper->precision * 10
			+ helper->str[helper->i] - '0';
		helper->i++;
	}
	if (helper->precision >= 0 && helper->pad_char == '0')
		helper->pad_char = ' ';
	helper->i--;
}
