/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahstou <mbahstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:50:45 by mbahstou          #+#    #+#             */
/*   Updated: 2020/03/04 11:29:24 by mbahstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init(t_printf *pack)
{
	pack->zero = 0;
	pack->dot = 0;
	pack->minus = 0;
	pack->aster = 0;
	pack->c = 0;
	pack->d = 0;
	pack->s = 0;
	pack->x = 0;
	pack->p = 0;
	pack->precision = 0;
	pack->width = 0;
}

void	ft_write(t_printf *pack)
{
	while (pack->format[pack->posi])
	{
		if (pack->format[pack->posi] == '%')
		{
			pack->posi++;
			ft_init(pack);
			if (!(ft_conversions(pack)))
				return ;
		}
		else
		{
			write(1, &pack->format[pack->posi], 1);
			pack->size++;
		}
		pack->posi++;
	}
}

int		ft_printf(const char *format, ...)
{
	t_printf *pack;

	if (!(pack = malloc(sizeof(t_printf))))
		return (-1);
	pack->format = format;
	pack->size = 0;
	pack->posi = 0;
	va_start(pack->arg, format);
	ft_write(pack);
	free(pack);
	return (pack->size);
}
