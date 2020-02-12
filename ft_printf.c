/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahstou <mbahstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:50:45 by mbahstou          #+#    #+#             */
/*   Updated: 2020/02/12 13:11:06 by mbahstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include <stdio.h>

void	ft_flags(t_printf *pack)
{
	if (pack->format[pack->posi] == '0' && pack->posi++)
		pack->zero = 1;
	if (pack->format[pack->posi] == '-' && pack->posi++)
		pack->minus = 1;
	if (pack->format[pack->posi] == '*' && pack->posi++)
		pack->aster = 1;
	if (pack->format[pack->posi] == '.' && pack->posi++)
	{
		pack->dot = 1;
		if (ft_isdigit(pack->format[pack->posi]) == 1)
		{
			pack->precision = ft_atoi(&pack->format[pack->posi]); // guardando la precision cuando encuentra el punto
			while (ft_isdigit(pack->format[pack->posi]) == 1)
				pack->posi++;
		}
		else if (pack->aster == 1)
		{
			pack->precision = va_arg(pack->arg, int); //cogiendo la precision como argumento en el caso de encontrar el '*'
			pack->posi++;
		}
	}
	if (ft_isdigit(pack->format[pack->posi]) == 1)
	{
		pack->width = ft_atoi(&pack->format[pack->posi]); //guardando el ancho
		while (ft_isdigit(pack->format[pack->posi]) == 1)
			pack->posi++;
	}
	else if (pack->aster == 1)
	{
		pack->width = va_arg(pack->arg, int); // cogiendo el ancho como argumento cuando se encuentra el '*'
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
	len = ft_strlen(pack->d);
	if (pack->zero == 1)
		if (pack->width > ft_strlen(pack->d))//meter los ceros hasta completar el ancho
			ft_printhings(pack, len, '0');
	while (pack->d[cont] != '\0')
	{
		write(1, &pack->d[cont], 1);
		cont++;
		pack->size++;
	}
}
void	ft_init(t_printf *pack)
{
	pack->zero = 0;
	pack->dot = 0;
	pack->minus = 0;
	pack->aster = 0;
	pack->c = 0;
	pack->d = 0;
	pack->precision = 0;
	pack->width = 0;
}

void	ft_char(t_printf *pack)
{
	void	*arg;
	arg = va_arg(pack->arg, void *);
	pack->c = (char)arg;
	if (pack->minus == 1)
	{
		write(1, &pack->c, 1);
		pack->size++;
		ft_printhings(pack, 1, ' ');
	}
	else if (pack->width > 1)
	{
		ft_printhings(pack, 1, ' ');
		write(1, &pack->c, 1);
		pack->size++;
	}
}
void	ft_istring(t_printf *pack)
{
	int		cont;

	cont = -1;
	pack->s = (char *)va_arg(pack->arg, void *);
	if (pack->dot == 1)
	{
		if (pack->precision != 0)
		{
			if (pack->precision < ft_strlen(pack->s))
			{
				pack->s = ft_substr(pack->s, cont + 1, pack->precision);
			}
			else
			{
				while (pack->s[++cont])
				{
					write(1, &pack->s[cont], 1);
					pack->size++;
				}
			}
		}
	}
	if (pack->width != 0)
	{
		if (pack->minus == 1)
		{
			while (pack->s[++cont])
			{
				write(1, &pack->s[cont], 1);
				pack->size++;
			}
			ft_printhings(pack, ft_strlen(pack->s), ' ');
		}
		else
		{
			ft_printhings(pack, ft_strlen(pack->s), ' ');
			while (pack->s[++cont])
			{
				write(1, &pack->s[cont], 1);
				pack->size++;
			}
		}
	}
}

void	ft_write(t_printf *pack)
{
	while (pack->format[pack->posi])
	{
		if (pack->format[pack->posi] == '%')
		{
			pack->posi++;
			ft_init(pack);
			while (ft_isalpha(pack->format[pack->posi]) != 1)
				ft_flags(pack);
		}
		else
		{
			write(1, &pack->format[pack->posi], 1);
			pack->size++;
		}
		if (pack->format[pack->posi] == 'c')
			ft_char(pack);
		else if (pack->format[pack->posi] == 'd')
			ft_int(pack);
		else if (pack->format[pack->posi] == 's')
			ft_istring(pack);
		pack->posi++;
	}
}

int		ft_printf(const char *format, ...)
{
	t_printf *pack;

	if (!(pack = malloc(sizeof(t_printf))))
		return (-1);
	pack->format = format;
	pack->size = 0;
	pack->posi = 0;
	va_start(pack->arg, format);
	ft_write(pack);
	return (pack->size);
}

int		main()
{
	printf("%d\n", ft_printf("hello %10.2s", "aloalo"));
	printf("%d\n", printf("hello %10.2s", "aloalo"));
	return (0);
}
