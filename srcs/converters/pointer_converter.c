/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_converter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 16:00:50 by jules             #+#    #+#             */
/*   Updated: 2020/12/18 16:23:52 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_p(t_helper *helper, va_list *list)
{
	unsigned long	val;
	char			*hexa;
	int				length;

	val = (unsigned long)va_arg(*list, void *);
	hexa = to_base(val, "0123456789abcdef");
	length = ft_strlen(hexa) + 2;
	helper->pad_len -= length;
	if (helper->r_pad)
	{
		while (*hexa)	
			fill_print(helper, *hexa++);
		pad_print(helper);
		return;
	}
	pad_print(helper);
	while (*hexa)	
		fill_print(helper, *hexa++);
}
