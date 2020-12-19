/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:26:14 by jules             #+#    #+#             */
/*   Updated: 2020/12/19 01:00:16 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_printf(t_helper *helper, va_list *list)
{
	while (helper->str[++helper->i])
	{
		write(1, "iter=", 5);
		ft_putnbr_fd(helper->i, 1);
		write(1, " | ", 3);
		if (helper->str[helper->i] != '%')
			fill_print(helper, helper->str[helper->i]);
		else if (helper->str[helper->i + 1])
			handle_expression(helper, list);
	}
}

int		ft_printf(const char *str, ...)
{
	t_helper	*helper;
	va_list		list;

	helper = new_helper(str);
	va_start(list, str);
	handle_printf(helper, &list);
	va_end(list);
	write(1, helper->print, helper->pos);
	return (helper->printed);
}
