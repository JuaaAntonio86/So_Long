/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantonio <juanantonio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:40:21 by juan-anm          #+#    #+#             */
/*   Updated: 2023/08/06 09:43:00 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchars(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstrs(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (!str)
		return (ft_putstrs("(null)"));
	while (str[i] != 0)
	{
		if (ft_putchars((char)str[i]) == -1)
			return (-1);
		res++;
		i++;
	}
	return (res);
}
