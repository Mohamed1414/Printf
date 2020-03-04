/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_widpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahstou <mbahstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:30:16 by mbahstou          #+#    #+#             */
/*   Updated: 2020/03/03 15:36:58 by mbahstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_widpointer(t_printf *pack, int cont, void *arg)
{
	if (arg == NULL && pack->dot == 1)
		ft_printhings(pack, ft_strlen(pack->p) + 1, ' ');
	else
		ft_printhings(pack, ft_strlen(pack->p) + 2, ' ');
	write(1, "0x", 2);
	pack->size += 2;
	if (arg != NULL || pack->dot == 0)
	{
		while (pack->p[cont])
		{
			write(1, &pack->p[cont++], 1);
			pack->size++;
		}
	}
}
