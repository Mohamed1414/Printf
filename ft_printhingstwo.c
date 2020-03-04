/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhingstwo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahstou <mbahstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:47:19 by mbahstou          #+#    #+#             */
/*   Updated: 2020/03/02 16:48:19 by mbahstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printhingstwo(t_printf *pack, int len, char c)
{
	int		j;

	j = pack->precision - len;
	while (j > 0)
	{
		write(1, &c, 1);
		j--;
		pack->size++;
	}
}
