/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_widstring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahstou <mbahstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:50:13 by mbahstou          #+#    #+#             */
/*   Updated: 2020/03/02 18:13:43 by mbahstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_widstring(t_printf *pack, int cont)
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
