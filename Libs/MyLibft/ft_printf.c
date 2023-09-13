/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantonio <juanantonio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:15:07 by juan-anm          #+#    #+#             */
/*   Updated: 2023/08/06 09:43:07 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *str, ...)
{
	va_list	val;
	int		i;
	int		res;
	int		tmp;

	va_start(val, str);
	tmp = 0;
	res = 0;
	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '%')
			tmp = (ft_typesort(val, (char)str[++i]));
		else
			tmp = (ft_putchars(str[i]));
		if (tmp == -1)
			return (-1);
		res += tmp;
		i++;
	}
	va_end(val);
	return (res);
}

int	ft_typesort(va_list val, char c)
{
	int	temp;

	temp = 0;
	if (c == 'c')
		return (ft_putchars(va_arg(val, int)));
	else if (c == 's')
		return (ft_putstrs(va_arg(val, char *)));
	else if (c == 'i' || c == 'd' )
		return (ft_putnbrs(va_arg(val, int), 0));
	else if (c == 'u')
		return (ft_unsputnbrs(va_arg(val, unsigned int), 0));
	else if (c == 'x' || c == 'X')
		return (ft_base_cnvrt(va_arg(val, int), c));
	else if (c == '%')
		return (ft_putchars('%'));
	else if (c == 'p')
	{
		temp = write(1, "0x", 2);
		if (temp == -1)
			return (-1);
		temp += (ft_base_pointer((unsigned long)va_arg(val, void *)));
		return (temp);
	}
	else
		return (0);
}
