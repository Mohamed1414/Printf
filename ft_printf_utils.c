/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahstou <mbahstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:47:49 by mbahstou          #+#    #+#             */
/*   Updated: 2020/02/26 19:18:29 by mbahstou         ###   ########.fr       */
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

static int		negative(unsigned long int *n, int *i)
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

char			*ft_itoa(long long int n)
{
	int						i;
	char					*p;
	int						cont;
	unsigned long int		num;
	unsigned long int				num2;

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

int		ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int		ft_strlen(const char *s)
{
	unsigned int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*p;
	unsigned int	l;

	if (s == 0)
		return (0);
	if (start > len)
		return (ft_strdup(""));
	l = ft_strlen(s + start);
	if (l < len)
		len = l;
	if (!(p = malloc((len + 1) * sizeof(char))))
		return (0);
	i = 0;
	while (i < len)
	{
		p[i] = s[i + start];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strdup(char *s1)
{
	char	*ptr;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	if (!(ptr = malloc(sizeof(char) * i + 1)))
		return (0);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
