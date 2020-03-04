/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahstou <mbahstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:45:46 by mbahstou          #+#    #+#             */
/*   Updated: 2020/03/02 16:46:16 by mbahstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printhings(t_printf *pack, int len, char c)
{
	int		j;

	j = pack->width - len;
	while (j > 0)
	{
		write(1, &c, 1);
		j--;
		pack->size++;
	}
}
