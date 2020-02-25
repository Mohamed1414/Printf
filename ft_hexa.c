/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahstou <mbahstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 17:59:43 by mbahstou          #+#    #+#             */
/*   Updated: 2020/02/25 16:14:02 by mbahstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_hexoa(unsigned long int arg)
{
	char					*num;
	int						len;
	unsigned long int		b;

	len = 2;
	b = arg;
	while (b /= 16)
		len++;
	if (!(num = (char *)malloc (sizeof(char) * len)))
		return (0);
	num[--len] = '\0';
	while (len--)
	{
		if ((arg % 16) < 10)
			num[len] = (arg % 16) + '0';
		else
			num[len] = (arg % 16) + 'W';
		arg = arg / 16;
	}
	return (num);
}

void	ft_hexa(t_printf *pack)
{
	void	*arg;
	int		cont;
	int		len;

	cont = 0;
	arg = va_arg(pack->arg, void *);
	pack->x = ft_hexoa((unsigned int)arg);
	len = ft_strlen(pack->x);
	if (pack->zero == 1 && pack->dot == 0)
	{
		if (pack->width > len)
			ft_printhings(pack, len, '0');
		while (pack->x[cont])
		{
			write(1, &pack->d[cont], 1);
			cont++;
			pack->size++;
		}
	}
	else if (pack->minus == 1)
	{
		if (pack->width > len)
		{
			while (pack->x[cont] != '\0')
			{
				write(1, &pack->d[cont], 1);
				cont++;
				pack->size++;
			}
			ft_printhings(pack, len, ' ');
		}
		else
		{
			while (pack->x[cont] != '\0')
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
			{
				ft_printhings(pack, pack->precision, ' ');
			}
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
			while (pack->x[cont] != '\0')
			{
				write(1, &pack->x[cont], 1);
				cont++;
				pack->size++;
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
