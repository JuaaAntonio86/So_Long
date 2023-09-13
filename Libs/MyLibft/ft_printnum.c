/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantonio <juanantonio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:10:30 by juan-anm          #+#    #+#             */
/*   Updated: 2023/08/06 09:43:20 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n);

int	ft_putnbrs(long long int n, int cont)
{
	unsigned int	div;
	unsigned int	res;

	res = 0;
	div = ft_intlen(n);
	if (n < 0)
	{
		n = n * -1;
		if (ft_putchars('-') == -1)
			return (-1);
		cont++;
	}
	while (div > 0)
	{
		res = '0' + (n / div);
		if (ft_putchars(res) == -1)
			return (-1);
		n = n % div;
		div = div / 10;
		cont++;
	}
	return (cont);
}

int	ft_unsputnbrs(long long int n, int cont)
{
	char	*base;
	int		temp;

	temp = 0;
	base = "0123456789";
	if (n > 9)
	{
		temp = ft_putnbrs((n / 10), cont);
		if (temp == -1)
			return (-1);
		cont += temp;
	}
	temp = ft_putchars((base[n % 10]));
	if (temp == -1)
		return (-1);
	cont += temp;
	return (cont);
}

static int	ft_intlen(int n)
{
	int	i;
	int	div;

	div = 1;
	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	while (i > 1)
	{
		div = div * 10;
		i--;
	}
	return (div);
}
