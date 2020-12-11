/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 21:23:10 by jules             #+#    #+#             */
/*   Updated: 2020/12/11 18:19:37 by jules            ###   ########.fr       */
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

void	write_padding(t_helper *helper, int precision)
{
	if (helper->r_pad)
		pad_print(helper);
	if (precision)
	{
		while (helper->precision > 0)
		{
			fill_print(helper, '0');
			helper->precision--;
		}
	}
	if (!helper->r_pad)
		pad_print(helper);
}
