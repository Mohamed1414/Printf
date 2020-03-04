/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_widint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahstou <mbahstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 19:23:11 by mbahstou          #+#    #+#             */
/*   Updated: 2020/03/02 19:24:47 by mbahstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_widint(t_printf *pack, int cont, int len)
{
	ft_printhings(pack, len, ' ');
	while (pack->d[cont] != '\0')
	{
		write(1, &pack->d[cont++], 1);
		pack->size++;
	}
}
