/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:26:14 by jules             #+#    #+#             */
/*   Updated: 2020/12/07 21:41:01 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_printf(t_helper *helper)
{
	while (helper->str[++helper->i])
	{
		if (helper->str[helper->i] != '%')
			fill_print(helper, helper->str[helper->i]);
		else if (helper->str[helper->i + 1])
			handle_expression(helper);
	}
}

int	ft_printf(const char *str, ...)
{
	t_helper	*helper;
	va_list		*list;

	helper = new_helper(str);
	va_start(list, str);
	handle_printf(helper);
	va_end(list);
	write(1, helper->str, printed += helper->pos + 1);
	return (printed);
}
