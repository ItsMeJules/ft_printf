/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_converters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 16:31:09 by jules             #+#    #+#             */
/*   Updated: 2020/12/04 21:38:26 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_converters(t_helper *helper, char c)
{
	if (c == 'c')
		return (handle_c(helper));
	else if (c == 's')
		return (handle_s(helper));
	else if (c == 'p')
		return (handle_p(helper));
	else if (c == 'd')
		return (handle_d(helper));
	else if (c == 'i')
		return (handle_i(helper));
	else if (c == 'u')
		return (handle_u(helper));
	else if (c == 'x')
		return (handle_x(helper));
	else if (c == 'X')
		return (handle_big_x(helper));
	else if (c == '%')
	{
		fill_print(helper, c);
		return (1);
	}
	return (0);
}
