/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahstou <mbahstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:21:25 by mbahstou          #+#    #+#             */
/*   Updated: 2020/03/03 18:49:25 by mbahstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct	s_printf {
	va_list		arg;
	const char	*format;
	int			posi;
	char		*s;
	char		*d;
	char		c;
	int			size;
	int			zero;
	int			minus;
	int			width;
	int			precision;
	int			dot;
	int			aster;
	char		*x;
	char		*p;
	char		*u;
}				t_printf;

char			*ft_itoa(long long int n);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_strlen(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strdup(char *s1);
int				ft_printf(const char *format, ...);
void			ft_printhings(t_printf *pack, int len, char c);
void			ft_printhingstwo(t_printf *pack, int len, char c);
void			ft_hexa(t_printf *pack);
char			*ft_hexoa(unsigned long int arg);
void			ft_unsigned(t_printf *pack);
void			ft_int(t_printf *pack);
void			ft_hexamay(t_printf *pack);
void			ft_percentage(t_printf *pack);
int				ft_conversions(t_printf *pack);
void			ft_char(t_printf *pack);
void			ft_flags(t_printf *pack);
void			ft_istring(t_printf *pack);
void			ft_pointer(t_printf *pack);
void			ft_wiandpre(t_printf *pack);
void			ft_flags(t_printf *pack);
void			ft_istring(t_printf *pack);
void			ft_prestring(t_printf *pack, int cont);
void			ft_impr(t_printf *pack, int cont);
void			ft_widstring(t_printf *pack, int cont);
void			ft_minusint(t_printf *pack, int cont, int len);
void			ft_preint(t_printf *pack, int cont, int len);
void			ft_zeroint(t_printf *pack, int cont, int len);
void			ft_widint(t_printf *pack, int cont, int len);
void			ft_prehex(t_printf *pack, int cont, int len);
void			ft_minushex(t_printf *pack, int cont, int len);
void			ft_zerohex(t_printf *pack, int cont, int len);
void			ft_gesthex(t_printf *pack, int cont, int len);
void			ft_widpointer(t_printf *pack, int cont, void *arg);
void			ft_minuspointer(t_printf *pack, int cont);
void			ft_pointer(t_printf *pack);
#endif
