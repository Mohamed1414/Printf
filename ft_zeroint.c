/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zerohex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahstou <mbahstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 19:09:33 by mbahstou          #+#    #+#             */
/*   Updated: 2020/03/02 19:12:08 by mbahstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_zeroint(t_printf *pack, int cont, int len)
{
	if (pack->d[cont] == '-')
	{
		write(1, &pack->d[cont++], 1);
		pack->size++;
	}
	if (pack->width > len)
		ft_printhings(pack, len, '0');
	while (pack->d[cont])
	{
		write(1, &pack->d[cont++], 1);
		pack->size++;
	}
}
