/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahstou <mbahstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:21:25 by mbahstou          #+#    #+#             */
/*   Updated: 2020/02/27 16:48:59 by mbahstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_printf {
	va_list	arg;
	const char *format;
	int		posi;
	char	*s;
	char	*d;
	char	c;
	int		size;
	int		zero;
	int 	minus;
	int 	width;
	int 	precision;
	int 	dot;
	int		aster;
	char	*x;
	char 	*p;
	char	*u;
} t_printf;
char		*ft_itoa(long long int n);
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
int			ft_isalpha(int c);
int			ft_strlen(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(char *s1);
int			ft_printf(const char *format, ...);
void		ft_printhings(t_printf *pack, int len, char c);
void 		ft_printhingstwo(t_printf *pack, int len, char c);
void		ft_hexa(t_printf *pack);
char		*ft_hexoa(unsigned long int arg);
void		ft_unsigned(t_printf *pack);
void		ft_int(t_printf *pack);
#endif