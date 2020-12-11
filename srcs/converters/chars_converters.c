/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars_converters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 20:41:23 by jules             #+#    #+#             */
/*   Updated: 2020/12/11 18:41:26 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_c(t_helper *helper, va_list *list)
{
	char	c;

	c = va_arg(*list, int);
	helper->pad_len--;
	write_padding(helper, 0);
	fill_print(helper, c);
}

void	handle_s(t_helper *helper, va_list *list)
{
	char	*s;
	int		i;
	int		len;

	s = va_arg(*list, char*);
	i = 0;
	len = ft_strlen(s);
	if (helper->precision >= 0 && helper->precision < len)
		len = helper->precision;
	helper->pad_len -= len;
	write_padding(helper, 0);
	while (len--)
		fill_print(helper, s[i++]);
}
