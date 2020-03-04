/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zerohex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahstou <mbahstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 14:18:46 by mbahstou          #+#    #+#             */
/*   Updated: 2020/03/03 14:19:34 by mbahstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_zerohex(t_printf *pack, int cont, int len)
{
	if (pack->width > len)
		ft_printhings(pack, len, '0');
	while (pack->x[cont])
	{
		write(1, &pack->x[cont++], 1);
		pack->size++;
	}
}
