/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prestring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahstou <mbahstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:15:18 by mbahstou          #+#    #+#             */
/*   Updated: 2020/03/02 18:00:24 by mbahstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_presmaller(t_printf *pack, int cont)
{
	if (pack->width > pack->precision)
	{
		if (pack->minus == 1)
		{
			while (++cont < pack->precision)
				ft_impr(pack, cont);
			ft_printhings(pack, pack->precision, ' ');
		}
		else
		{
			ft_printhings(pack, pack->precision, ' ');
			while (++cont < pack->precision)
				ft_impr(pack, cont);
		}
	}
	else
	{
		while (++cont < pack->precision)
			ft_impr(pack, cont);
	}
}

void	ft_wbiggerp(t_printf *pack, int cont)
{
	if (pack->minus == 1)
	{
		while (pack->s[++cont])
			ft_impr(pack, cont);
		ft_printhings(pack, ft_strlen(pack->s), ' ');
	}
	else
	{
		ft_printhings(pack, ft_strlen(pack->s), ' ');
		while (pack->s[++cont])
			ft_impr(pack, cont);
	}
}

void	ft_prestring(t_printf *pack, int cont)
{
	if (pack->precision != 0)
	{
		if (pack->precision < ft_strlen(pack->s))
			ft_presmaller(pack, cont);
		else if (pack->width >= pack->precision)
			ft_wbiggerp(pack, cont);
		else if (pack->precision > pack->width && ft_strlen(pack->s) == 0)
		{
			ft_printhings(pack, 0, ' ');
			while (pack->s[++cont])
				ft_impr(pack, cont);
		}
		else
		{
			while (pack->s[++cont])
				ft_impr(pack, cont);
		}
	}
	else
		ft_printhings(pack, 0, ' ');
}
