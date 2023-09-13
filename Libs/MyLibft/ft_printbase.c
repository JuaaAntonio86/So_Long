/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantonio <juanantonio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:45:57 by juan-anm          #+#    #+#             */
/*   Updated: 2023/08/06 09:42:36 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_base_pointer(unsigned long long pntr)
{
	char	*base;
	int		cont;
	int		temp;

	temp = 0;
	cont = 0;
	base = "0123456789abcdef";
	if (pntr > 15)
	{
		temp = ft_base_pointer(pntr / 16);
		if (temp == -1)
			return (-1);
		cont += temp;
	}
	temp = ft_putchars((base[pntr % 16]));
	if (temp == -1)
		return (-1);
	cont += temp;
	return (cont);
}

int	ft_base_cnvrt(unsigned int nbr, char x)
{
	char	*base;
	int		cont;
	int		temp;

	temp = 0;
	cont = 0;
	base = "0123456789abcdef";
	if (x == 'X')
		base = "0123456789ABCDEF";
	if (nbr > 15)
	{
		temp = ft_base_cnvrt(nbr / 16, x);
		if (temp == -1)
			return (-1);
		cont += temp;
	}
	temp = ft_putchars((base[nbr % 16]));
	if (temp == -1)
		return (-1);
	cont += temp;
	return (cont);
}
