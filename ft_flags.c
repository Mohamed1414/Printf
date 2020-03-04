/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahstou <mbahstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:09:05 by mbahstou          #+#    #+#             */
/*   Updated: 2020/03/02 17:09:21 by mbahstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flags(t_printf *pack)
{
	if (pack->format[pack->posi] == '0' && pack->posi++)
		pack->zero = 1;
	if (pack->format[pack->posi] == '-' && pack->posi++)
		pack->minus = 1;
	if (pack->format[pack->posi] == '*' && pack->posi++)
		pack->aster = 1;
	ft_wiandpre(pack);
}
