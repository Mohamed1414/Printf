/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahstou <mbahstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:50:45 by mbahstou          #+#    #+#             */
/*   Updated: 2020/02/05 18:05:25 by mbahstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include <stdio.h>

void	ft_flags(t_printf *pack)
{
	if (pack->format[pack->posi] == '0')
		pack->zero = 1;
	if (pack->format[pack->posi] == '-')
		pack->minus = 1;
	if (pack->format[pack->posi] == '*')
		pack->aster = 1;
	if (pack->format[pack->posi] == '.')
		pack->dot = 1;
		pack->posi++;
		if(ft_isdigit(pack->format[pack->posi] == 1))
		{
			pack->precision = ft_atoi(&pack->format[pack->posi]);
			while (ft_isdigit(pack->format[pack->posi] == 1))
				pack->posi++;
		}
		else if (pack->aster == 1)
		{
			pack->precision = ft_atoi(va_arg(pack->arg, int));
			pack->posi++;
		}
	pack->posi++;
	if (ft_isdigit(pack->format[pack->posi] == 1))
	{
		pack->width = ft_atoi(&pack->format[pack->posi]);
		while (ft_isdigit(pack->format[pack->posi] == 1))
			pack->posi++;
	}
	else if (pack->aster == 1)
	{
		pack->width = ft_atoi(va_arg(pack->arg, int));
		pack->posi++;
	}
}
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

void	ft_int(t_printf *pack)
{
	void	*arg;
	int		cont;
	int		len;

	cont = 0;
	arg = va_arg(pack->arg, void *);
	pack->d = ft_itoa((int)arg);
	while (pack->d[cont] != '\0')
	{
		if (pack->zero == 1)
		{
		//	pack->width = ft_atoi(&pack->format[pack->posi]); // guardar como int el ancho despues de que aparezca el flag 0
			if(pack->width > ft_strlen(pack->d))//meter los ceros hasta completar el ancho
			{
				len = ft_strlen(pack->d);
				ft_printhings(pack, len, '0');
			}
			while (ft_isdigit(pack->format[pack->posi]) == 1) // avanzar la posición de format hasta que se encuentre con la letra
				pack->posi++;
		}
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
	pack->dot = 0;
	pack->minus = 0;
	pack->aster = 0;
	pack->c = 0;
	pack->d = 0;
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
			ft_flags(pack);	
		}
		else
		{
			write(1, &pack->format[pack->posi], 1);
			pack->size++;
		}
		if (pack->format[pack->posi] == 'c')
			ft_char(pack);
		if (pack->format[pack->posi] == 'd')
			ft_int(pack);
		pack->posi++;
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
	printf("%d\n", ft_printf("hello %06d world %c hola que tal %c %033d", 15, 'l', 'a', -13));
	printf("%d\n", printf("hello %06d world %c hola que tal %c %033d", 15, 'l', 'a', -13));
	return (0);
}
