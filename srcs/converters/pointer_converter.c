/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_converter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 16:00:50 by jules             #+#    #+#             */
/*   Updated: 2020/12/19 01:27:11 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*to_unsigned_base(unsigned long nbr, char *base)
{
	static char buffer[50];
	char		*ptr;
	int			base_len;

	ptr = &buffer[49];
	*ptr = 0;
	if (nbr == 0)
		*--ptr = 0;
	base_len = ft_strlen(base);
	while (nbr != 0)
	{
		*--ptr = base[nbr % base_len];
		nbr /= base_len;
	}
	return (ptr);
}

void	handle_p(t_helper *helper, va_list *list)
{
	unsigned long	val;
	char			*hexa;
	int				length;

	val = (unsigned long)va_arg(*list, void *);
	hexa = to_unsigned_base(val, "0123456789abcdef");
	length = ft_strlen(hexa) + 2;
	helper->pad_len -= length;
	if (!helper->r_pad)
	{
		fill_print(helper, '0');
		fill_print(helper, 'x');
		if (val <= 0)
			fill_print(helper '0');
		while (*hexa)
			fill_print(helper, *hexa++);
		pad_print(helper);
		return ;
	}
	pad_print(helper);
	fill_print(helper, '0');
	fill_print(helper, 'x');
	if (val <= 0)
		fill_print(helper '0');
	while (*hexa)
		fill_print(helper, *hexa++);
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
