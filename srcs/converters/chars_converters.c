/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars_converters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 20:41:23 by jules             #+#    #+#             */
/*   Updated: 2020/12/20 11:09:09 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_c(t_helper *helper, va_list *list)
{
	char	c;

	c = va_arg(*list, int);
	helper->pad_len--;
	if (!helper->r_pad)
	{
		fill_print(helper, c);
		pad_print(helper);
		return ;
	}
	else
		pad_print(helper);
	fill_print(helper, c);
}

void	write_string(t_helper *helper, char *s, int len, int alloc)
{
	int	i;

	i = 0;
	while (len--)
		fill_print(helper, s[i++]);
	if (alloc)
		free(s);
}

void	len_pad_checks(t_helper *helper, int alloc, int *len)
{
	if (helper->precision >= 0 && helper->precision < *len)
	{
		if (!alloc)
			*len = helper->precision;
		else
			*len = 0;
	}
	helper->pad_len -= *len;
	helper->precision = -1; /* resets the precision for errors handling */
}

void	handle_s(t_helper *helper, va_list *list)
{
	char	*s;
	int		len;
	int		alloc;

	s = va_arg(*list, char*);
	alloc = 0;
	if (s == NULL)
	{
		s = ft_strdup("(null)");
		alloc = 1;
	}
	len = ft_strlen(s);
	len_pad_checks(helper, alloc, &len);
	if (!helper->r_pad)
	{
		write_string(helper, s, len, alloc);
		pad_print(helper);
		return ;
	}
	else
		pad_print(helper);
	write_string(helper, s, len, alloc);
}
