/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars_converters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 20:41:23 by jules             #+#    #+#             */
/*   Updated: 2020/12/07 21:33:32 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_c(t_helper *helper, va_list *list)
{
	char	c;

	c = va_arg(*list, int);
	helper->pad_len--;
	write_padding(helper, 0);
}

int	handle_s(t_helper *helper, va_list *list)
{
	char	*s;
	int		i;

	s = va_arg(*list, char*);
	i = 0;
	helper->pad_len -= ft_strlen(s);
	write_padding(helper, 0);
	while (s[i])
		fill_print(helper, s[i++]);
}
