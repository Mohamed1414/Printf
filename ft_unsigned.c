/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahstou <mbahstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:01:51 by mbahstou          #+#    #+#             */
/*   Updated: 2020/02/26 19:47:09 by mbahstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_unsigned(t_printf *pack)
{
	void	*arg;
	int		cont;
	int		len;

	cont = 0;
	arg = va_arg(pack->arg, void *);
	pack->u = ft_itoa((unsigned int)arg);
	len = ft_strlen(pack->u);
	if (pack->zero == 1 && pack->dot == 0)
	{
		if (pack->width > len)
			ft_printhings(pack, len, '0');
		while (pack->u[cont])
		{
			write(1, &pack->u[cont], 1);
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
				ft_printhingstwo(pack, len, '0');
				if (pack->u[cont] == '0')
					ft_printhings(pack, pack->precision, ' ');
				else
				{
					while (pack->u[cont] != '\0')
					{
						write(1, &pack->u[cont], 1);
						cont++;
						pack->size++;
					}
					ft_printhings(pack, pack->precision, ' ');
				}
			}
			else
			{
				ft_printhingstwo(pack, len, '0');
				while (pack->u[cont] != '\0')
				{
					write(1, &pack->u[cont], 1);
					cont++;
					pack->size++;
				}
			}
		}
		else if (pack->width > len)
		{
			while (pack->u[cont] != '\0')
			{
				write(1, &pack->u[cont], 1);
				cont++;
				pack->size++;
			}
			ft_printhings(pack, len, ' ');
		}
		else
		{
			while (pack->u[cont] != '\0')
			{
				write(1, &pack->u[cont], 1);
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
			}
			ft_printhingstwo(pack, len, '0');
			while (pack->u[cont] != '\0')
			{
				write(1, &pack->u[cont], 1);
				cont++;
				pack->size++;
			}
		}
		else if (pack->width > pack->precision)
		{
			if (pack->precision < len)
				ft_printhings(pack, len, ' ');
			else
				ft_printhings(pack, pack->precision, ' ');
			if (pack->u[cont] == '0')
				return ;
			else
			{
				while (pack->u[cont] != '\0')
				{
					write(1, &pack->u[cont], 1);
					cont++;
					pack->size++;
				}
			}
		}
		else
		{
			if (pack->u[cont] == '0')
				return ;
			else
			{
				while (pack->u[cont] != '\0')
				{
					write(1, &pack->u[cont], 1);
					cont++;
					pack->size++;
				}
			}
		}
	}
	else if (pack->width > len && pack->dot == 0)
	{
		ft_printhings(pack, len, ' ');
		while (pack->u[cont] != '\0')
		{
			write(1, &pack->u[cont], 1);
			cont++;
			pack->size++;
		}
	}
	else
	{
		while (pack->u[cont] != '\0')
		{
			write(1, &pack->u[cont], 1);
			cont++;
			pack->size++;
		}
	}
}
