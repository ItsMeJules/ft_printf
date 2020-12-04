/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:10:10 by jules             #+#    #+#             */
/*   Updated: 2020/12/04 21:38:32 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include "../libft/includes/libft.h"

#define PRINT_BUFF 100
#define CONVERTERS "cspdiuxX"

typedef struct	s_helper
{
	const char	*str;
	char		*print;
	char		pad_char;
	int			i;
	int			pos;
	int			pad_len;
	int			r_pad;
}				t_helper;

t_helper	*new_helper(const char *str);
void		fill_printf(t_helper *helper, char c);
int			handle_expression(t_helper *helper);

int			handle_c(t_helper *helper, va_list *list);
int			handle_s(t_helper *helper, va_list *list);
int			handle_p(t_helper *helper, va_list *list);
int			handle_d(t_helper *helper, va_list *list);
int			handle_i(t_helper *helper, va_list *list);
int			handle_u(t_helper *helper, va_list *list);
int			handle_x(t_helper *helper, va_list *list);
int			handle_big_x(t_helper *helper, va_list *list);

#endif
