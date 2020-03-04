/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minuspointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahstou <mbahstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:37:53 by mbahstou          #+#    #+#             */
/*   Updated: 2020/03/03 15:38:46 by mbahstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_minuspointer(t_printf *pack, int cont)
{
	write(1, "0x", 2);
	pack->size += 2;
	while (pack->p[cont])
	{
		write(1, &pack->p[cont++], 1);
		pack->size++;
	}
	ft_printhings(pack, ft_strlen(pack->p) + 2, ' ');
}
