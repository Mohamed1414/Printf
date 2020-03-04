/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minusint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahstou <mbahstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 18:16:03 by mbahstou          #+#    #+#             */
/*   Updated: 2020/03/02 19:18:13 by mbahstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_widbigpre(t_printf *pack, int cont, int len)
{
	if (pack->d[cont] == '-')
	{
		write(1, &pack->d[cont++], 1);
		pack->size++;
		pack->precision++;
	}
	if (pack->d[0] == '0')
		ft_printhingstwo(pack, 0, '0');
	else
		ft_printhingstwo(pack, len, '0');
	if (pack->d[cont] == '0')
		ft_printhings(pack, pack->precision, ' ');
	else
	{
		while (pack->d[cont] != '\0')
		{
			write(1, &pack->d[cont++], 1);
			pack->size++;
		}
		if (pack->precision > len)
			ft_printhings(pack, pack->precision, ' ');
		else
			ft_printhings(pack, len, ' ');
	}
}

void	ft_widsmallpre(t_printf *pack, int cont, int len)
{
	if (pack->d[cont] == '-')
	{
		write(1, &pack->d[cont++], 1);
		len--;
		pack->size++;
	}
	ft_printhingstwo(pack, len, '0');
	while (pack->d[cont] != '\0')
	{
		write(1, &pack->d[cont++], 1);
		pack->size++;
	}
}

void	ft_minusint(t_printf *pack, int cont, int len)
{
	if (pack->dot == 1)
	{
		if (pack->width > pack->precision)
			ft_widbigpre(pack, cont, len);
		else
			ft_widsmallpre(pack, cont, len);
	}
	else if (pack->width > len)
	{
		while (pack->d[cont] != '\0')
		{
			write(1, &pack->d[cont++], 1);
			pack->size++;
		}
		ft_printhings(pack, len, ' ');
	}
	else
	{
		while (pack->d[cont] != '\0')
		{
			write(1, &pack->d[cont++], 1);
			pack->size++;
		}
	}
}
