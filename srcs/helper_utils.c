/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:55:27 by jules             #+#    #+#             */
/*   Updated: 2020/12/11 18:53:20 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_helper	*new_helper(const char *str)
{
	t_helper	*helper;

	if (!(helper = malloc(sizeof(t_helper))))
		return (NULL);
	if (!(helper->print = ft_memalloc(sizeof(char) * PRINT_BUFF)))
		return (NULL);
	helper->str = str;
	helper->pad_char = ' ';
	helper->printed = 0;
	helper->i = -1;
	helper->pad_len = 0;
	helper->pos = 0;
	helper->r_pad = 1;
	helper->precision = -1;
	return (helper);
}

void		fill_print(t_helper *helper, char c)
{
	if (helper->pos == PRINT_BUFF)	
	{
		write(1, helper->str, PRINT_BUFF);
		helper->pos = 0;
	}
	helper->print[helper->pos++] = c;
	helper->printed++;
}

void		handle_expression(t_helper *helper, va_list *list)
{
	while (helper->str[++helper->i])
	{
		if (ft_strchr(CONVERTERS, helper->str[helper->i]))
		{
			handle_converter(helper, list, helper->str[helper->i]);		
			break ;
		}
		handle_flags(helper);
	}
}
