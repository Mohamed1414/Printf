/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gesthex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahstou <mbahstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:12:11 by mbahstou          #+#    #+#             */
/*   Updated: 2020/03/03 15:13:32 by mbahstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_gesthex(t_printf *pack, int cont, int len)
{
	if (pack->zero == 1 && pack->dot == 0)
		ft_zerohex(pack, cont, len);
	else if (pack->minus == 1)
		ft_minushex(pack, cont, len);
	else if (pack->dot == 1)
		ft_prehex(pack, cont, len);
	else if (pack->width > len && pack->dot == 0)
	{
		ft_printhings(pack, len, ' ');
		while (pack->x[cont] != '\0')
		{
			write(1, &pack->x[cont++], 1);
			pack->size++;
		}
	}
	else
	{
		while (pack->x[cont])
		{
			write(1, &pack->x[cont++], 1);
			pack->size++;
		}
	}
}
