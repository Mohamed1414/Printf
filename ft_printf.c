/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahstou <mbahstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:50:45 by mbahstou          #+#    #+#             */
/*   Updated: 2020/02/28 13:44:05 by mbahstou         ###   ########.fr       */
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
	if (ft_isdigit(pack->format[pack->posi]) == 1)
	{
		pack->width = ft_atoi(&pack->format[pack->posi]); //guardando el ancho
		while (ft_isdigit(pack->format[pack->posi]) == 1)
			pack->posi++;
	}
	else if (pack->aster == 1)
		pack->width = va_arg(pack->arg, int);
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
}
void	ft_printhings(t_printf *pack, int len, char c)
{
	int		j;
	j = pack->width - len;
	//gestionar cuando la precision esta activada en los ints
	while (j > 0)
	{
		write(1, &c, 1);
		j--;
		pack->size++;
	}
}

void ft_printhingstwo(t_printf *pack, int len, char c)
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
/*
void	ft_int(t_printf *pack)
{
	void	*arg;
	int		cont;
	int		len;

	cont = 0;
	arg = va_arg(pack->arg, void *);
	pack->d = ft_itoa((int)arg);
	len = ft_strlen(pack->d);
	if (pack->zero == 1 && pack->dot == 0)
	{
		if (pack->width > len)
			ft_printhings(pack, len, '0');
		while (pack->d[cont])
		{
			write(1, &pack->d[cont], 1);
			cont++;
			pack->size++;
		}
	}
	else if (pack->minus == 1)
	{
		if (pack->width > len)
		{
			while (pack->d[cont] != '\0')
			{
				write(1, &pack->d[cont], 1);
				cont++;
				pack->size++;
			}
			ft_printhings(pack, len, ' ');
		}
		else
		{
			while (pack->d[cont] != '\0')
			{
				write(1, &pack->d[cont], 1);
				cont++;
				pack->size++;
			}
		}
	}
	else if (pack->dot == 1)
	{
		if (pack->precision > len)
		{
			if (pack->width != 0)
			{
				ft_printhings(pack, pack->precision, ' ');
			}
			ft_printhingstwo(pack, len, '0');
			while (pack->d[cont] != '\0')
			{
				write(1, &pack->d[cont], 1);
				cont++;
				pack->size++;
			}
		}
		else if (pack->width > len)
		{
			ft_printhings(pack, len, ' ');
			while (pack->d[cont] != '\0')
			{
				write(1, &pack->d[cont], 1);
				cont++;
				pack->size++;
			}
		}
		else
		{
			while (pack->d[cont] != '\0')
			{
				write(1, &pack->d[cont], 1);
				cont++;
				pack->size++;
			}
		}
	}
	else if (pack->width > len && pack->dot == 0)
	{
		ft_printhings(pack, len, ' ');
		while (pack->d[cont] != '\0')
		{
			write(1, &pack->d[cont], 1);
			cont++;
			pack->size++;
		}
	}
	else
	{
		while (pack->d[cont] != '\0')
		{
			write(1, &pack->d[cont], 1);
			cont++;
			pack->size++;
		}
	}
}*/

char	*ft_hexoamay(unsigned long int arg)
{
	char					*num;
	int						len;
	unsigned long int		b;

	len = 2;
	b = arg;
	while (b /= 16)
		len++;
	if (!(num = (char *)malloc (sizeof(char) * len)))
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
	void	*arg;
	int		cont;

	cont = 0;
	arg = va_arg(pack->arg, void *);
	pack->x = ft_hexoamay((unsigned int)arg);
	while (pack->x[cont])
	{
		write(1, &pack->x[cont], 1);
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
	pack->s = 0;
	pack->x = 0;
	pack->p = 0;
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
	else
	{
		write(1, &pack->c, 1);
		pack->size++;
	}
}
void	ft_istring(t_printf *pack)
{
	int		cont;

	cont = -1;
	pack->s = (char *)va_arg(pack->arg, void *);
	if (!pack->s)
		pack->s = "(null)";
	if (pack->dot == 1)
	{
		if (pack->precision != 0)
		{
			if (pack->precision < ft_strlen(pack->s))
			{
				if (pack->width > pack->precision)
				{
					if (pack->minus == 1)
					{
						while (++cont < pack->precision)
						{
							write(1, &pack->s[cont], 1);
							pack->size++;
						}
						ft_printhings(pack, pack->precision, ' ');
					}
					else
					{
						ft_printhings(pack, pack->precision, ' ');
						while (++cont < pack->precision)
						{
							write(1, &pack->s[cont], 1);
							pack->size++;
						}
					}
				}
				else
				{
					while (++cont < pack->precision)
					{
						write(1, &pack->s[cont], 1);
						pack->size++;
					}
				}
			}
			else if (pack->width >= pack->precision)
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
	if (pack->width != 0 && pack->dot == 0)
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
	else if (pack->dot == 0)
	{
		while (pack->s[++cont])
		{
			write(1, &pack->s[cont], 1);
			pack->size++;
		}
	}
}

void	ft_pointer(t_printf *pack)
{
	void	*arg;
	int		cont;

	cont = 0;
	arg = va_arg(pack->arg, void *);
	pack->p = ft_hexoa((unsigned long int)arg);
	if (pack->minus == 1)
	{
		write(1, "0x", 2);
		pack->size += 2;
		while (pack->p[cont])
		{
			write(1, &pack->p[cont], 1);
			cont++;
			pack->size++;
		}
		ft_printhings(pack, ft_strlen(pack->p) + 2, ' ');
	}
	else if (pack->width > ft_strlen(pack->p))
	{
		if (arg == NULL && pack->dot == 1)
			ft_printhings(pack, ft_strlen(pack->p) + 1, ' ');
		else
			ft_printhings(pack, ft_strlen(pack->p) + 2, ' ');
		write(1, "0x", 2);
		pack->size += 2;
		if (arg != NULL || pack->dot == 0)
		{
			while (pack->p[cont])
			{
				write(1, &pack->p[cont], 1);
				cont++;
				pack->size++;
			}
		}
	}
	else if (arg == NULL && pack->dot == 1)
	{
		write(1, "0x", 2);
		pack->size += 2;
	}
	else
	{
		write(1, "0x", 2);
		pack->size += 2;
		while (pack->p[cont])
		{
			write(1, &pack->p[cont], 1);
			cont++;
			pack->size++;
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
			if (ft_isalpha(pack->format[pack->posi]) != 1)
				ft_flags(pack);
			if (pack->format[pack->posi] == 'c')
				ft_char(pack);
			else if (pack->format[pack->posi] == 'd' || pack->format[pack->posi] == 'i')
				ft_int(pack);
			else if (pack->format[pack->posi] == 's')
				ft_istring(pack);
			else if (pack->format[pack->posi] == 'x')
				ft_hexa(pack);
			else if (pack->format[pack->posi] == 'X')
				ft_hexamay(pack);
			else if (pack->format[pack->posi] == 'p')
				ft_pointer(pack);
			else if (pack->format[pack->posi] == 'u')
				ft_unsigned(pack);
		}
		else
		{
			write(1, &pack->format[pack->posi], 1);
			pack->size++;
		}
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
/*
int		main()
{
	printf("%d\n", ft_printf("%0-10.5i", -216));
//	printf("%d\n", printf("%0-10.5i", -216));
	return (0);
}
*/