/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexamay.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahstou <mbahstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 15:07:09 by mbahstou          #+#    #+#             */
/*   Updated: 2020/03/03 19:00:26 by mbahstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_hexoamay(unsigned long int arg)
{
	char					*num;
	int						len;
	unsigned long int		b;

	len = 2;
	b = arg;
	while (b /= 16)
		len++;
	if (!(num = (char *)malloc(sizeof(char) * len)))
		return (0);
	num[--len] = '\0';
	while (len--)
	{
		if ((arg % 16) < 10)
			num[len] = (arg % 16) + '0';
		else
			num[len] = (arg % 16) + '7';
		arg = arg / 16;
	}
	return (num);
}

void	ft_hexamay(t_printf *pack)
{
	void			*arg;
	int				cont;
	int				len;

	cont = 0;
	arg = va_arg(pack->arg, void *);
	pack->x = ft_hexoamay((unsigned int)arg);
	len = ft_strlen(pack->x);
	ft_gesthex(pack, cont, len);
}
