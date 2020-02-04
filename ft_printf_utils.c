/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahstou <mbahstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:47:49 by mbahstou          #+#    #+#             */
/*   Updated: 2020/02/04 19:18:01 by mbahstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	int		i;
	int		n;
	int		a;
	int		sign;

	i = 0;
	n = 1;
	a = 0;
	sign = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' ||
			str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -n;
		i++;
		sign++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		a = (a * 10) + str[i] - '0';
		i++;
	}
	return (sign > 1 ? 0 : a * n);
}

static int		negative(long int *n, int *i)
{
	int cont;

	cont = 0;
	if (*n < 0)
	{
		*n = *n * -1;
		cont += 1;
		*i += 1;
	}
	return (cont);
}

char			*ft_itoa(int n)
{
	int				i;
	char			*p;
	int				cont;
	long int		num;
	long int		num2;

	i = 2;
	num = n;
	cont = negative(&num, &i);
	num2 = num;
	while (num /= 10)
		i++;
	if (!(p = malloc((i) * sizeof(char))))
		return (0);
	p[--i] = '\0';
	while (i-- > 0)
	{
		p[i] = num2 % 10 + '0';
		num2 = num2 / 10;
	}
	if (cont > 0)
		p[i + 1] = '-';
	return (p);
}
