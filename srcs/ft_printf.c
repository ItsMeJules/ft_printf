/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:26:14 by jules             #+#    #+#             */
/*   Updated: 2020/12/04 21:39:27 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_printf(t_helper *helper)
{
	int	printed;

	printed = 0;
	while (helper->str[++helper->i])
	{
		if (helper->str[helper->i] != '%')
		{
			fill_print(helper, helper->str[helper->i]);
			printed++;
		}
		else if (helper->str[helper->i + 1])
			printed += handle_expression(helper);
	}
	return (printed);
}

int	ft_printf(const char *str, ...)
{
	t_helper	*helper;
	va_list		*list;
	int			printed;

	helper = new_helper(str);
	va_start(list, str);
	printed = handle_printf(helper);
	va_end(list);
	write(1, helper->str, helper->pos + 1);
	return (printed);
}
