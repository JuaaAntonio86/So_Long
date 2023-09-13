/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantonio <juanantonio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:38:12 by juan-anm          #+#    #+#             */
/*   Updated: 2023/08/06 09:46:28 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strj;
	int		i;
	int		j;

	j = 0;
	i = 0;
	strj = malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (!strj)
		return (NULL);
	while (s1[i])
	{
		strj[j] = s1[i];
		j++;
		i++;
	}
	i = 0;
	while (s2[i])
	{
		strj[j] = s2[i];
		j++;
		i++;
	}
	strj[j] = 0;
	return (strj);
}
