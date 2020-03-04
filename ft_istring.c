/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahstou <mbahstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:12:45 by mbahstou          #+#    #+#             */
/*   Updated: 2020/03/02 18:06:14 by mbahstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_istring(t_printf *pack)
{
	int		cont;

	cont = -1;
	pack->s = (char *)va_arg(pack->arg, void *);
	if (!pack->s)
		pack->s = "(null)";
	if ((pack->width < 0))
	{
		pack->width *= -1;
		pack->minus = 1;
	}
	if (pack->precision < 0)
		pack->dot = 0;
	if (pack->dot == 1)
		ft_prestring(pack, cont);
	if (pack->width != 0 && pack->dot == 0)
		ft_widstring(pack, cont);
	else if (pack->dot == 0)
	{
		while (pack->s[++cont])
			ft_impr(pack, cont);
	}
}
