/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahstou <mbahstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 12:59:41 by mbahstou          #+#    #+#             */
/*   Updated: 2020/03/02 16:36:50 by mbahstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conversions(t_printf *pack)
{
	if (ft_isalpha(pack->format[pack->posi]) != 1)
		ft_flags(pack);
	if (pack->format[pack->posi] == '%')
		ft_percentage(pack);
	else if (pack->format[pack->posi] == 'c')
		ft_char(pack);
	else if (pack->format[pack->posi] == 'd' || pack->format[pack->posi] == 'i')
		ft_int(pack);
	else if (pack->format[pack->posi] == 's')
		ft_istring(pack);
	else if (pack->format[pack->posi] == 'x')
		ft_hexa(pack);
	else if (pack->format[pack->posi] == 'X')
		ft_hexamay(pack);
	else if (pack->format[pack->posi] == 'p')
		ft_pointer(pack);
	else if (pack->format[pack->posi] == 'u')
		ft_unsigned(pack);
	else
		return (0);
	return (1);
}
