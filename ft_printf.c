/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahstou <mbahstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:50:45 by mbahstou          #+#    #+#             */
/*   Updated: 2020/02/04 18:43:19 by mbahstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include <stdio.h>


void	ft_IsInt(t_printf *pack)
{
	void	*arg;
	int		cont;

	cont = 0;
	arg = va_arg(pack->arg, void *);
	pack->d = ft_itoa((int)arg);
	while (pack->d[cont] != '\0')
	{
		write(1, &pack->d[cont], 1);
		cont++;
		pack->size++;
	}
}
void	ft_init(t_printf *pack, const char *format)
{
	pack->format = format;
	pack->size = 0;
	pack->posi = 0;
	pack->zero = 0;
	pack->c = 0;
	pack->d = 0;
}
int		ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

void	ft_char(t_printf *pack)
{
	void	*arg;
	arg = va_arg(pack->arg, void *);
	pack->c = (char)arg;
	write(1, &pack->c, 1);
	pack->size++;
}

void	ft_write(t_printf *pack, const char *format)
{
	while (format[pack->posi])
	{
		if (pack->format[pack->posi] == '%')
		{
			pack->posi++;
			if (pack->format[pack->posi] == '0')
				pack->zero = 1;
			if (pack->format[pack->posi] == '-')
				pack->minus = 1;
			if (pack->format[pack->posi] == 'c')
				ft_char(pack);
			if (pack->format[pack->posi] == 'd')
				ft_IsInt(pack);
			pack->posi++;
		}
		else
		{
			write(1, &pack->format[pack->posi], 1);
			pack->posi++;
			pack->size++;
		}
	}
}

int		ft_printf(const char *format, ...)
{
	t_printf *pack;

	if (!(pack = malloc(sizeof(t_printf))))
		return (-1);
	ft_init(pack, format);
	va_start(pack->arg, format);
	ft_write(pack, format);
	return (pack->size);
}

int		main()
{
	printf("%d\n", ft_printf("hello %d world %c hola que tal %c %d", 15, 'l', 'a', -13));
	printf("%d\n", printf("hello %d world %c hola que tal %c %d", 15, 'l', 'a', -13));
	return (0);
}
