/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahstou <mbahstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:01:51 by mbahstou          #+#    #+#             */
/*   Updated: 2020/03/03 18:59:28 by mbahstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unsigned(t_printf *pack)
{
	void	*arg;
	int		cont;

	cont = 0;
	arg = va_arg(pack->arg, void *);
	pack->d = ft_itoa((unsigned int)arg);
	if (pack->width < 0)
	{
		pack->width *= -1;
		pack->minus = 1;
	}
	if (pack->zero == 1 && pack->dot == 0 && pack->minus == 0)
		ft_zeroint(pack, cont, ft_strlen(pack->d));
	else if (pack->minus == 1)
		ft_minusint(pack, cont, ft_strlen(pack->d));
	else if (pack->dot == 1)
		ft_preint(pack, cont, ft_strlen(pack->d));
	else if (pack->width > ft_strlen(pack->d) && pack->dot == 0)
		ft_widint(pack, cont, ft_strlen(pack->d));
	else
		while (pack->d[cont] != '\0')
		{
			write(1, &pack->d[cont++], 1);
			pack->size++;
		}
}
