/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:10:10 by jules             #+#    #+#             */
/*   Updated: 2020/12/19 18:30:10 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/includes/libft.h"

# define PRINT_BUFF 100
# define CONVERTERS "%cspdiuxX"

typedef struct	s_helper
{
	const char	*str;
	char		*print;
	char		pad_char;
	int			printed;
	int			i;
	int			pos;
	int			pad_len;
	int			r_pad;
	int			precision;
}				t_helper;

t_helper		*new_helper(const char *str);
void			fill_print(t_helper *helper, char c);
void			handle_expression(t_helper *helper, va_list *list);

void			handle_converter(t_helper *helper, va_list *list, char c);
void			handle_flags(t_helper *helper, va_list *list, char c);

void			pad_print(t_helper *helper);
void			precision_print(t_helper *helper);
void			prec_pad_checks(t_helper *helper, int val, int digits);

int				count_digits(long val);
char			*to_base(unsigned long nbr, char *base);

void			handle_d(t_helper *helper, va_list *list);
void			handle_u(t_helper *helper, va_list *list);
void			handle_x(t_helper *helper, va_list *list, int maj);

void			handle_c(t_helper *helper, va_list *list);
void			handle_s(t_helper *helper, va_list *list);

void			handle_p(t_helper *helper, va_list *list);
void			handle_percent(t_helper *helper);

void			handle_pad(t_helper *helper, int rpad, va_list *list);
void			handle_zero_pad(t_helper *helper, va_list *list);
void			handle_precision(t_helper *helper, va_list *list);

int				ft_printf(const char *s, ...);

#endif
