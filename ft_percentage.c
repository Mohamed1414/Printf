/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percentage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahstou <mbahstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 17:09:37 by mbahstou          #+#    #+#             */
/*   Updated: 2020/02/28 17:14:05 by mbahstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_percentage(t_printf *pack)
{
	pack->c = '%';
	if (pack->zero == 1)
	{
		ft_printhings(pack, 1, '0');
		write(1, &pack->c, 1);
		pack->size++;
	}
	else if (pack->minus == 1)
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
