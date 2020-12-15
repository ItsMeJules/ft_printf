/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 16:31:09 by jules             #+#    #+#             */
/*   Updated: 2020/12/15 15:20:55 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_converter(t_helper *helper, va_list *list, char c)
{
	if (c == 'c')
		handle_c(helper, list);
	else if (c == 's')
		handle_s(helper, list);
	//else if (c == 'p')
	//	handle_p(helper, list);
	else if (c == 'd' || c == 'i')
		handle_d(helper, list);
	else if (c == 'u')
		handle_u(helper, list);
	//else if (c == 'x')
	//	handle_x(helper, list);
	//else if (c == 'X')
	//	handle_big_x(helper, list);
	else if (c == '%')
		fill_print(helper, c);
}
