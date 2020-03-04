/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahstou <mbahstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 18:45:08 by mbahstou          #+#    #+#             */
/*   Updated: 2020/03/02 19:17:17 by mbahstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prebig(t_printf *pack, int cont, int len)
{
	if (pack->precision > len)
	{
		if (pack->width != 0)
		{
			if (pack->d[cont] == '-')
				ft_printhings(pack, pack->precision + 1, ' ');
			else
				ft_printhings(pack, pack->precision, ' ');
			if (pack->d[cont] == '-')
			{
				write(1, &pack->d[cont++], 1);
				len--;
				pack->size++;
			}
		}
		if (pack->d[cont] == '-')
		{
			write(1, &pack->d[cont++], 1);
			pack->size++;
			len--;
		}
		ft_printhingstwo(pack, len, '0');
		while (pack->d[cont] != '\0' && pack->size++)
			write(1, &pack->d[cont++], 1);
	}
}

void	ft_presmall(t_printf *pack, int cont, int len)
{
	if (pack->precision < len)
		if (pack->d[cont] == '0')
			ft_printhings(pack, 0, ' ');
		else
			ft_printhings(pack, len, ' ');
	else
		ft_printhings(pack, pack->precision, ' ');
	if (pack->d[cont] == '0')
		return ;
	else
	{
		while (pack->d[cont] != '\0')
		{
			write(1, &pack->d[cont++], 1);
			pack->size++;
		}
	}
}

void	ft_preint(t_printf *pack, int cont, int len)
{
	if (pack->precision > len)
		ft_prebig(pack, cont, len);
	else if (pack->width > pack->precision)
		ft_presmall(pack, cont, len);
	else
	{
		if (pack->d[cont] == '0')
			return ;
		else
		{
			while (pack->d[cont] != '\0')
			{
				write(1, &pack->d[cont++], 1);
				pack->size++;
			}
		}
	}
}
