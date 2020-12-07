/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 21:23:10 by jules             #+#    #+#             */
/*   Updated: 2020/12/07 21:25:44 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_padding(t_helper *helper, int precision)
{
	if (helper->r_pad)
	{
		while (pad_len--)
			fill_print(helper, helper->pad_char);
	}
	if (precision)
	{
		while (helper->precision--)
			fill_print(helper, '0');
		helper->precison = -1;
	}
	if (!helper->r_pad)
	{
		while (pad_len--)
			fill_print(helper, helper->pad_char);
		helper->pad_len = -1;
	}
	helper->pad_len = -1;
}
