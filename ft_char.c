/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahstou <mbahstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:40:13 by mbahstou          #+#    #+#             */
/*   Updated: 2020/03/02 16:40:29 by mbahstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char(t_printf *pack)
{
	void	*arg;

	arg = va_arg(pack->arg, void *);
	pack->c = (char)arg;
	if (pack->minus == 1)
	{
		write(1, &pack->c, 1);
		pack->size++;
		ft_printhings(pack, 1, ' ');
	}
	else if (pack->width > 1)
	{
		ft_printhings(pack, 1, ' ');
		write(1, &pack->c, 1);
		pack->size++;
	}
	else
	{
		write(1, &pack->c, 1);
		pack->size++;
	}
}
