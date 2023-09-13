/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantonio <juanantonio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:58:40 by juan-anm          #+#    #+#             */
/*   Updated: 2023/08/06 09:45:46 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchrgnl(char *s, int c)
{
	int		i;
	char	*a;

	a = (char *)s;
	i = 0;
	while (a[i] != '\0')
	{
		if (a[i] == (unsigned char)c)
			return (&a[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return (&a[i]);
	else
		return (NULL);
}

int	ft_strlengnl(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoingnl(char *dst, char *src)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!dst)
		return (NULL);
	str = malloc(((ft_strlen(dst) + ft_strlen(src)) + 1) * sizeof(char));
	if (!str)
	{
		return (ft_freegnl(&dst));
	}
	i = 0;
	j = 0;
	while (dst[i] != '\0')
	{
		str[i] = dst[i];
		i++;
	}
	while (src[j] != '\0')
		str[i++] = src[j++];
	str[i] = '\0';
	free(dst);
	return (str);
}
