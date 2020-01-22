/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahstou <mbahstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:50:45 by mbahstou          #+#    #+#             */
/*   Updated: 2020/01/22 18:17:06 by mbahstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>

void	imprchar(char c)
{
	write(1, &c, 1);
}

int	ft_printf(const char *format, ...)
{
	int	i;
	char *string;

	i = 0;
	string = (char *)format;
	while(string[i] != '\0')
	{
		imprchar(i);
		i++;
	}
	return (0);
}

int main()
{
	char *string;
	
	string = "hola que tal";
	ft_printf(string);
	return (0);
}
