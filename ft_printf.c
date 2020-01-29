/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahstou <mbahstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:50:45 by mbahstou          #+#    #+#             */
/*   Updated: 2020/01/29 16:44:39 by mbahstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int			i;
	t_printf	*pack;

	i = 0;
	if (!(pack = malloc(sizeof(t_printf))))
		return (-1);
	while (format[i] && format[i] != '%')
		pack->size += write(1, &format[i++], 1);
}
