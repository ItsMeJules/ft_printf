/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_converter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 16:00:50 by jules             #+#    #+#             */
/*   Updated: 2020/12/19 23:20:56 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_chars(t_helper *helper, char *hexa, int val)
{
	fill_print(helper, '0');
	fill_print(helper, 'x');
	if (val == 0)
	{
		if (helper->precision == -1)
			fill_print(helper, '0');
	}
	while (*hexa)
		fill_print(helper, *hexa++);
}

void	handle_p(t_helper *helper, va_list *list)
{
	unsigned long	val;
	char			*hexa;
	int				length;

	val = (unsigned long)va_arg(*list, void *);
	hexa = to_base(val, "0123456789abcdef");
	length = ft_strlen(hexa) + 2;
	helper->pad_len -= length;
	if (val == 0 && helper->precision == -1)
		helper->pad_len--;
	if (!helper->r_pad)
	{
		fill_chars(helper, hexa, val);
		pad_print(helper);
		return ;
	}
	pad_print(helper);
	fill_chars(helper, hexa, val);
}

void	handle_percent(t_helper *helper)
{
	helper->pad_len--;
	if (!helper->r_pad)
	{
		fill_print(helper, '%');
		pad_print(helper);
		return ;
	}
	else
		pad_print(helper);
	fill_print(helper, '%');
}
