/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexamay.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahstou <mbahstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 15:07:09 by mbahstou          #+#    #+#             */
/*   Updated: 2020/02/28 15:42:43 by mbahstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*ft_hexoamay(unsigned long int arg)
{
	char					*num;
	int						len;
	unsigned long int		b;

	len = 2;
	b = arg;
	while (b /= 16)
		len++;
	if (!(num = (char *)malloc(sizeof(char) * len)))
		return (0);
	num[--len] = '\0';
	while (len--)
	{
		if ((arg % 16) < 10)
			num[len] = (arg % 16) + '0';
		else
			num[len] = (arg % 16) + '7';
		arg = arg / 16;
	}
	return (num);
}


void	ft_hexamay(t_printf *pack)
{
	void	*arg;
	int		cont;
	int		len;

	cont = 0;
	arg = va_arg(pack->arg, void *);
	pack->x = ft_hexoamay((unsigned int)arg);
	len = ft_strlen(pack->x);
	if (pack->zero == 1 && pack->dot == 0)
	{
		if (pack->width > len)
			ft_printhings(pack, len, '0');
		while (pack->x[cont])
		{
			write(1, &pack->x[cont], 1);
			cont++;
			pack->size++;
		}
	}
	else if (pack->minus == 1)
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
						write(1, &pack->x[cont], 1);
						cont++;
						pack->size++;
					}
			}
			else if (pack->precision < pack->width)
			{
				if (pack->x[0] == '0')
					ft_printhingstwo(pack, 0, '0');
				else
					ft_printhingstwo(pack, len, '0');
				while (pack->x[cont] != '\0' && pack->x[0] != '0')
				{
					write(1, &pack->x[cont], 1);
					cont++;
					pack->size++;
				}
				if (len < pack->precision)
					ft_printhings(pack, pack->precision, ' ');
				else if (pack->x[0] == '0')
					ft_printhings(pack, 0, ' ');
				else
					ft_printhings(pack, len, ' ');
			}
		}
		if (pack->width > len && pack->dot == 0)
		{
			while (pack->x[cont] != '\0')
			{
				write(1, &pack->x[cont], 1);
				cont++;
				pack->size++;
			}
			ft_printhings(pack, len, ' ');
		}
		else
		{
			while (pack->x[cont] != '\0' && pack->x[0] != '0')
			{
				write(1, &pack->x[cont], 1);
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
				ft_printhings(pack, pack->precision, ' ');
			ft_printhingstwo(pack, len, '0');
			while (pack->x[cont] != '\0')
			{
				write(1, &pack->x[cont], 1);
				cont++;
				pack->size++;
			}
		}
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
					write(1, &pack->x[cont], 1);
					cont++;
					pack->size++;
				}
			}
		}
		else
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
					write(1, &pack->x[cont], 1);
					cont++;
					pack->size++;
				}
			}
		}
	}
	else if (pack->width > len && pack->dot == 0)
	{
		ft_printhings(pack, len, ' ');
		while (pack->x[cont] != '\0')
		{
			write(1, &pack->x[cont], 1);
			cont++;
			pack->size++;
		}
	}
	else
	{
		while (pack->x[cont])
		{
			write(1, &pack->x[cont], 1);
			cont++;
			pack->size++;
		}
	}
}