/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:10:10 by jules             #+#    #+#             */
/*   Updated: 2020/12/03 18:16:05 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include "../libft/includes/libft.h"
#define PRINT_BUFF 100

typedef struct	s_helper
{
	const char	*str;
	int			pad_len;
	int			r_pad;
	char		pad_char;
}				t_helper;

t_helper	*new_helper(const char *str);

#endif
