/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahstou <mbahstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:21:25 by mbahstou          #+#    #+#             */
/*   Updated: 2020/02/03 18:18:33 by mbahstou         ###   ########.fr       */
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
	char	c;
	int		size;
	int		zero;
	int 	minus;
	int 	width;
	int 	precision;
	int 	dot;
	int		aster;
} t_printf;
#endif