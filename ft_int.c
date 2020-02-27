/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahstou <mbahstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:38:18 by mbahstou          #+#    #+#             */
/*   Updated: 2020/02/27 17:55:29 by mbahstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_int(t_printf *pack)
{
	void	*arg;
	int		cont;
	int		len;

	cont = 0;
	arg = va_arg(pack->arg, void *);
	pack->d = ft_itoa((int)arg);
	len = ft_strlen(pack->d);
	if (pack->zero == 1 && pack->dot == 0)
	{
		if (pack->d[cont] == '-')
		{
			write(1, &pack->d[cont], 1);
			cont++;
			pack->size++;
		}
		if (pack->width > len)
			ft_printhings(pack, len, '0');
		while (pack->d[cont])
		{
			write(1, &pack->d[cont], 1);
			cont++;
			pack->size++;
		}
	}
	else if (pack->minus == 1)
	{
		if (pack->dot == 1)
		{
			if (pack->width > pack->precision)
			{
				if (pack->d[cont] == '0')
					ft_printhingstwo(pack, 0, '0');
				else
					ft_printhingstwo(pack, len, '0');
				if (pack->d[cont] == '0')
					ft_printhings(pack, pack->precision, ' ');
				else
				{
					while (pack->d[cont] != '\0')
					{
						write(1, &pack->d[cont], 1);
						cont++;
						pack->size++;
					}
					if (pack->precision > len)
						ft_printhings(pack, pack->precision, ' ');
					else
						ft_printhings(pack, len, ' ');
				}
			}
			else
			{
				ft_printhingstwo(pack, len, '0');
				while (pack->d[cont] != '\0')
				{
					write(1, &pack->d[cont], 1);
					cont++;
					pack->size++;
				}
			}
		}
		else if (pack->width > len)
		{
			while (pack->d[cont] != '\0')
			{
				write(1, &pack->d[cont], 1);
				cont++;
				pack->size++;
			}
			ft_printhings(pack, len, ' ');
		}
		else
		{
			while (pack->d[cont] != '\0')
			{
				write(1, &pack->d[cont], 1);
				cont++;
				pack->size++;
			}
		}
	}
	else if (pack->dot == 1)
	{
		if (pack->precision > len)
		{
			if (pack->width != 0)
			{
				ft_printhings(pack, pack->precision, ' ');
				if (pack->d[cont] == '-')
				{
					write(1, &pack->d[cont], 1);
					len--;
					cont++;
					pack->size++;
				}
			}
			if (pack->d[cont] == '-')
			{
				write(1, &pack->d[cont], 1);
				cont++;
				pack->size++;
				len--;
			}
			ft_printhingstwo(pack, len, '0');
			while (pack->d[cont] != '\0')
			{
				write(1, &pack->d[cont], 1);
				cont++;
				pack->size++;
			}
		}
		else if (pack->width > pack->precision)
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
					write(1, &pack->d[cont], 1);
					cont++;
					pack->size++;
				}
			}
		}
		else
		{
			if (pack->d[cont] == '0')
				return ;
			else
			{
				while (pack->d[cont] != '\0')
				{
					write(1, &pack->d[cont], 1);
					cont++;
					pack->size++;
				}
			}
		}
	}
	else if (pack->width > len && pack->dot == 0)
	{
		ft_printhings(pack, len, ' ');
		while (pack->d[cont] != '\0')
		{
			write(1, &pack->d[cont], 1);
			cont++;
			pack->size++;
		}
	}
	else
	{
		while (pack->d[cont] != '\0')
		{
			write(1, &pack->d[cont], 1);
			cont++;
			pack->size++;
		}
	}
}
