/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minushex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahstou <mbahstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 12:38:14 by mbahstou          #+#    #+#             */
/*   Updated: 2020/03/03 19:04:23 by mbahstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_else(t_printf *pack, int cont, int len)
{
	if (pack->width > len && pack->dot == 0)
	{
		while (pack->x[cont] != '\0')
		{
			write(1, &pack->x[cont++], 1);
			pack->size++;
		}
		ft_printhings(pack, len, ' ');
	}
	else
	{
		while (pack->x[cont] != '\0' && pack->x[0] != '0')
		{
			write(1, &pack->x[cont++], 1);
			pack->size++;
		}
	}
}

int		ft_prec(t_printf *pack, int cont, int len)
{
	if (pack->x[0] == '0')
		ft_printhingstwo(pack, 0, '0');
	else
		ft_printhingstwo(pack, len, '0');
	while (pack->x[cont] != '\0' && pack->x[0] != '0')
	{
		write(1, &pack->x[cont++], 1);
		pack->size++;
	}
	if (len < pack->precision)
		ft_printhings(pack, pack->precision, ' ');
	else if (pack->x[0] == '0')
		ft_printhings(pack, 0, ' ');
	else
		ft_printhings(pack, len, ' ');
	return (cont);
}

void	ft_minushex(t_printf *pack, int cont, int len)
{
	if (pack->dot == 1)
	{
		if (pack->width < pack->precision)
		{
			ft_printhingstwo(pack, len, '0');
			if (pack->x[0] == '0')
				return ;
			else
				while (pack->x[cont] != '\0' && pack->x[0] != '0')
				{
					write(1, &pack->x[cont++], 1);
					pack->size++;
				}
		}
		else if (pack->precision < pack->width)
			cont = ft_prec(pack, cont, len);
	}
	ft_else(pack, cont, len);
}
