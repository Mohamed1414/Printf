/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prehex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahstou <mbahstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 11:35:50 by mbahstou          #+#    #+#             */
/*   Updated: 2020/03/03 15:28:37 by mbahstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prebighex(t_printf *pack, int cont, int len)
{
	if (pack->width != 0)
		ft_printhings(pack, pack->precision, ' ');
	ft_printhingstwo(pack, len, '0');
	while (pack->x[cont] != '\0')
	{
		write(1, &pack->x[cont++], 1);
		pack->size++;
	}
}

void	ft_else2(t_printf *pack, int cont, int len)
{
	if (pack->x[0] == '0')
	{
		ft_printhings(pack, 0, ' ');
		return ;
	}
	else
	{
		ft_printhings(pack, len, ' ');
		while (pack->x[cont] != '\0')
		{
			write(1, &pack->x[cont++], 1);
			pack->size++;
		}
	}
}

void	ft_prehex(t_printf *pack, int cont, int len)
{
	if (pack->precision > len)
		ft_prebighex(pack, cont, len);
	else if (pack->width > len)
	{
		if (pack->x[0] == '0')
		{
			ft_printhings(pack, 0, ' ');
			return ;
		}
		else
		{
			ft_printhings(pack, len, ' ');
			while (pack->x[cont] != '\0')
			{
				write(1, &pack->x[cont++], 1);
				pack->size++;
			}
		}
	}
	else
		ft_else2(pack, cont, len);
}
