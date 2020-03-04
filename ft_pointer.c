/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahstou <mbahstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:42:13 by mbahstou          #+#    #+#             */
/*   Updated: 2020/03/03 15:42:42 by mbahstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pointer(t_printf *pack)
{
	void	*arg;
	int		cont;

	cont = 0;
	arg = va_arg(pack->arg, void *);
	pack->p = ft_hexoa((unsigned long int)arg);
	if (pack->minus == 1)
		ft_minuspointer(pack, cont);
	else if (pack->width > ft_strlen(pack->p))
		ft_widpointer(pack, cont, arg);
	else if (arg == NULL && pack->dot == 1)
	{
		write(1, "0x", 2);
		pack->size += 2;
	}
	else
	{
		write(1, "0x", 2);
		pack->size += 2;
		while (pack->p[cont])
		{
			write(1, &pack->p[cont++], 1);
			pack->size++;
		}
	}
}
