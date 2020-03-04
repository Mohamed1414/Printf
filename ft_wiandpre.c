/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wiandpre.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahstou <mbahstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:51:49 by mbahstou          #+#    #+#             */
/*   Updated: 2020/03/02 16:54:32 by mbahstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_wiandpre(t_printf *pack)
{
	if (ft_isdigit(pack->format[pack->posi]) == 1)
	{
		pack->width = ft_atoi(&pack->format[pack->posi]);
		while (ft_isdigit(pack->format[pack->posi]) == 1)
			pack->posi++;
	}
	else if (pack->aster == 1)
		pack->width = va_arg(pack->arg, int);
	if (pack->format[pack->posi] == '.' && pack->posi++)
	{
		pack->dot = 1;
		if (ft_isdigit(pack->format[pack->posi]) == 1)
		{
			pack->precision = ft_atoi(&pack->format[pack->posi]);
			while (ft_isdigit(pack->format[pack->posi]) == 1)
				pack->posi++;
		}
		else if (pack->format[pack->posi] == '*')
		{
			pack->precision = va_arg(pack->arg, int);
			pack->posi++;
		}
	}
}
